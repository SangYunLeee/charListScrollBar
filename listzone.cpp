#include "listzone.h"
#include <QDebug>
#include <iostream>





ListZone::ListZone(QObject *parent) : QObject(parent)
{
    chosungList = {"ㄱ","ㄲ","ㄴ","ㄷ","ㄸ","ㄹ","ㅁ","ㅂ","ㅃ","ㅅ","ㅆ","ㅇ","ㅈ","ㅉ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ"};
}

QVariant ListZone::convertedList() const
{
    return QVariant::fromValue(m_listForZone);
}

void ListZone::setConvertedList(const QVariant &convertedList)
{
    m_convertedList = convertedList;
}

QVariant ListZone::convertedCharList() const
{
    return QVariant::fromValue(m_listForChar);
}

void ListZone::setConvertedCharList(const QVariant &convertedCharList)
{
    m_convertedCharList = convertedCharList;
}




void ListZone::getListStringFromQml(const QVariant &folderPath)
{
    QString s_folder = folderPath.toString();
    qDebug() << "s_folder: " << s_folder;

    //make list empty
    if(!m_listForZone.isEmpty()){
        for(auto* m_list : m_listForZone)
            delete m_list;
        m_listForZone.clear();
    }

    //add MusicList
    //filtering Mp3
    QStringList filter;
    filter << "*";
    QDirIterator it(s_folder.replace(0,8,""), filter, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot);

    QList<QString> stringList;
    QList<QString> stringList_eng;

    QChar a;
    it.next(); //first next() is empty
    while (it.hasNext()){
        a = it.fileName().at(0);
        if(a>=0xac00 && a<=0xd7a3) // = if hangle
            stringList << it.fileName();
        else
            stringList_eng << it.fileName();
        it.next();
    }
    stringList.sort();
    stringList_eng.sort();

    for(auto str : stringList_eng)
        stringList << str;

    int instA = 0;
    for(auto str: stringList){
        if(str.at(0)>=0xac00 && str.at(0)<=0xd7a3){
            instA =  (str.at(0).unicode()-0xac00)/(21*28);
            m_listForZone << new Zone(str,chosungList.at(instA));
        }else
            m_listForZone << new Zone(str);
    }

                             //   CHAR LIST   //

    //make list_Char empty
    if(!m_listForChar.isEmpty()){
        for(auto* m_list : m_listForChar)
            delete m_list;
        m_listForChar.clear();
    }

    QList<QString> list;
    QList<QString> list_eng;
    QString qChar;
    QString ga = "가";

    //
    for(QObject* zone : m_listForZone){
        qChar = (static_cast<Zone*>(zone))->zone().front();
        //insert Korean
        if(qChar>=0xac00 && qChar<=0xd7a3){ //if korean, then...
            int a = qChar.at(0).unicode(); //a = unicode
            int b = ga.at(0).unicode();    // b = 0xac00
            int c = (a-b)/(21*28);          // 0~17
            if(!list.contains(chosungList.at( c )))
            list <<chosungList.at( c );
        }
        else //insert English
            if(!list_eng.contains(qChar.toUpper()))
                list_eng << qChar.toUpper();

    }
    list.sort();
    list_eng.sort();
    for(auto str : list_eng)
        list << str;

    //input Char_List to cnv_Char_List
    for(QString m_char : list )
         m_listForChar << new Zone(m_char);
    for(QObject* zone : m_listForChar){
        qChar = (static_cast<Zone*>(zone))->zone();

        //indexing to cnv_list_char
        int cnt = 0;
        for(QObject* text : m_listForZone){
            if (qChar.toLower() == (static_cast<Zone*>(text))->zone().front().toLower() ){
                (static_cast<Zone*>(zone))->setIndex(QString::number(cnt));
                break;
            }
            cnt++;
        }
    }
    for(QObject* zone : m_listForChar){
        qDebug() << "index: " << (static_cast<Zone*>(zone))->index();
    }
    emit convertedListChanged();
    emit convertedCharListChanged();

    qDebug() << "end";



}

void ListZone::test()
{
    QString a = "가나다아ㄱㄴㄷㄹㅁㅂ";
    QString e = "다각다아ㄱㄴㄷㄹㅁㅂ";
    QChar ga = a.at(0);
    QChar b = e.at(0);
    int gaInt = ga.unicode();
    int targetInt = b.unicode();
    int extractIntChar = (targetInt - gaInt)/(21 * 28); // joongsung (21) * chosung (28)
    qDebug() << "check:" << chosungList.at(0);
    std::cout<< "unicode:" << extractIntChar << std::endl;

}
