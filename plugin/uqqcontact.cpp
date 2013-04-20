#include "uqqcontact.h"


UQQContact::UQQContact(QObject *parent) :
    QObject(parent)
{
}

UQQContact::~UQQContact() {
}

/*
 *       {
 *           "friends":[{"flag":0,"uin":123456,"categories":0},...,{...}],
 *           "marknames":[{"uin":123456,"markname":""},...,{...}],
 *           "categories":[{"index":1,"sort":4,"name":""},...,,{...}],
 *           "vipinfo":[{"vip_level":0,"u":1234567,"is_vip":0},...,{...}],
 *           "info":[{"face":0,"flag":0,"nick":"","uin":1234567},...,{...}]
 *       }
*/
void UQQContact::setContactData(const QVariantMap &map) {
    setCategories(map.value("categories").toList());
    setMembers(map.value("friends").toList());
    setMarknames(map.value("marknames").toList());
    setVipInfo(map.value("vipinfo").toList());
    setNickname(map.value("info").toList());
}

void UQQContact::addMember(UQQMember *member) {
    if (member) {
        Q_ASSERT(!member->uin().isEmpty());
        m_members.insert(member->uin(), member);
        addMemberToCategory(member->gid(), member);
    }
}

void UQQContact::setMembers(const QVariantList &list) {
    QVariantMap m;
    qDebug() << "set members...";
    for (int i = 0; i < list.size(); i++) {
        m = list.at(i).toMap();
        addMember(new UQQMember(m.value("categories").toULongLong(), m.value("uin").toString(), this));
    }
    qDebug() << "set members done, total members:" << list.size();
}

void UQQContact::setMarknames(const QVariantList &list) {
    QVariantMap m;
    UQQMember *member;
    qDebug() << "set member marknames...";
    for (int i = 0; i < list.size(); i++) {
        m = list.at(i).toMap();
        member = this->member(m.value("uin").toString());
        Q_CHECK_PTR(member);
        if (member)
            member->setMarkname(m.value("markname").toString());
    }
    qDebug() << "set member marknames done";
}

void UQQContact::setVipInfo(const QVariantList &list) {
    QVariantMap m;
    UQQMember *member;
    qDebug() << "set members vip info...";
    for (int i = 0; i < list.size(); i++) {
        m = list.at(i).toMap();
        member = this->member(m.value("u").toString());
        Q_CHECK_PTR(member);
        if (member) {
            member->setVip(m.value("is_vip").toBool());
            member->setVipLevel(m.value("vip_level").toInt());
        }
    }
    qDebug() << "set members vip info done.";
}

void UQQContact::setNickname(const QVariantList &list) {
    QVariantMap m;
    UQQMember *member;
    qDebug() << "set member nickname...";
    for (int i = 0; i < list.size(); i++) {
        m = list.at(i).toMap();
        member = this->member(m.value("uin").toString());
        Q_CHECK_PTR(member);
        if (member)
            member->setNickname(m.value("nick").toString());
    }
    qDebug() << "set member nickname done.";
}

void UQQContact::setCategories(const QVariantList &list) {
    QVariantMap m;
    int index = UQQCategory::BuddyCategoryId;
    UQQCategory *category = Q_NULLPTR;
    qDebug() << "set categories...";
/*
    category = new UQQCategory();
    category->setName("在线好友");
    category->setId(UQQCategory::OnlineCategoryId);
    m_categories.append(category);
*/
    category = new UQQCategory(this);
    category->setName("我的好友");
    category->setId(index);
    m_categories.append(category);

    for (int i = 0; i < list.size(); i++) {
        m = list.at(i).toMap();
        category = new UQQCategory(this);
        category->setName(m.value("name").toString());
        category->setId(++index);
        m_categories.append(category);
    }
    category = new UQQCategory();
    category->setName("陌生人");
    category->setId(++index);
    m_categories.append(category);
    qDebug() << "set categories done, total categories:" << index + 1;
}

void UQQContact::addMemberToCategory(quint64 id, UQQMember *member) {
    Q_CHECK_PTR(member);
    if (id == UQQCategory::IllegalCategoryId)
        return;
    UQQCategory *cat = getCategory(id);
    if (cat) {
        cat->addMember(member);
    } else {
        qDebug() << "find a stranger:" << id << member->uin();
        categories().last()->addMember(member); // add to stranger category
    }
}

UQQCategory * UQQContact::getCategory(quint64 id) {
    for (int i = 0; i < m_categories.size(); i++) {
        if (m_categories.at(i)->id() == id) {
            return m_categories.at(i);
        }
    }
    //qDebug() << "catetory" << gid << "not found!";
    return Q_NULLPTR;
}

QList<UQQCategory *> &UQQContact::categories() {
    return m_categories;
}

QHash<QString, UQQMember*> &UQQContact::members() {
    return m_members;
}

UQQMember *UQQContact::member(const QString &uin) {
    Q_ASSERT(uin.length() > 0);
    if (m_members.contains(uin))
        return m_members.value(uin);
    else
        return Q_NULLPTR;
}

void UQQContact::setOnlineBuddies(const QVariantList &list) {
    QVariantMap m;
    QString status;
    QString uin;
    UQQMember *member;

    qDebug() << "set online buddies...";
    // the list may contain duplicate entry
    for (int i = 0; i < list.size(); i++) {
        m = list.at(i).toMap();
        status = m.value("status").toString();
        uin = m.value("uin").toString();
        Q_ASSERT(uin.length() > 0);
        member = this->member(uin);
        member->setStatus(UQQMember::statusIndex(status));
        member->setClientType(m.value("client_type").toInt());
        getCategory(member->gid())->incOnline();
    }
    qDebug() << "set online buddies done. online members:" << list.size();
}

void UQQContact::setBuddyStatus(QString uin, int status, int clientType) {
    Q_ASSERT(uin.length() > 0);
    UQQMember *member = this->member(uin);
    Q_CHECK_PTR(member);

    int oldStatus = member->status();
    member->setStatus(status);
    member->setClientType(clientType);

    if (oldStatus == status) return;

    UQQCategory *cat = getCategory(member->gid());
    Q_CHECK_PTR(cat);

    if (oldStatus == UQQMember::OfflineStatus) {  // offline -> online
        cat->incOnline();
    } else if (status == UQQMember::OfflineStatus){    // online -> offline
        cat->decOnline();
    } else {
    }
}

QList<UQQMember *> UQQContact::membersInCategory(quint64 id, bool sorted) {
    UQQCategory *c = getCategory(id);
    Q_CHECK_PTR(c);
    if (sorted)
        return c->sortedMembers();
    else
        return c->members();
}

void UQQContact::addSessMessage(UQQMessage *sessMessage) {
    if (sessMessage) {
        m_sessMessages.append(sessMessage);
    }
}

QList<UQQMessage *> UQQContact::getSessMessage(const QString &uin) {
    UQQMessage *message;
    QList<UQQMessage *> messages;
    for (int i = 0; i < m_sessMessages.size(); i++) {
        message = m_sessMessages.at(i);
        if (message->src() == uin) {
            messages.append(message);
        }
    }
    return messages;
}
