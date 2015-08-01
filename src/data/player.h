/***************************************************************************
    *   Copyright (C) 2015 by Renaud Guezennec                                *
    *   http://renaudguezennec.homelinux.org/accueil,3.html                   *
    *                                                                         *
    *   rolisteam is free software; you can redistribute it and/or modify     *
    *   it under the terms of the GNU General Public License as published by  *
    *   the Free Software Foundation; either version 2 of the License, or     *
    *   (at your option) any later version.                                   *
    *                                                                         *
    *   This program is distributed in the hope that it will be useful,       *
    *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
    *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
    *   GNU General Public License for more details.                          *
    *                                                                         *
    *   You should have received a copy of the GNU General Public License     *
    *   along with this program; if not, write to the                         *
    *   Free Software Foundation, Inc.,                                       *
    *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
    ***************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"
/**
 * @brief Represents a player.
 *
 * Players are stored in PlayersList. A player may have some characters.
 */
class Player : public Person
{

public:
    /**
     * @brief Player
     * @param name
     * @param color
     * @param master
     * @param link
     */
    Player(const QString & name, const QColor & color, bool master = false, NetworkLink * link = NULL);
    /**
     * @brief Player
     * @param uuid
     * @param name
     * @param color
     * @param master
     * @param link
     */
    Player(const QString & uuid, const QString & name, const QColor & color, bool master = false, NetworkLink * link = NULL);
    /**
     * @brief Player
     * @param data
     * @param link
     */
    Player(NetworkMessageReader & data, NetworkLink * link = NULL);
    /**
     * @brief ~Player
     */
    virtual ~Player();
    /**
     * @brief fill
     * @param message
     */
    void fill(NetworkMessageWriter & message);
    /**
     * @brief link
     * @return
     */
    NetworkLink * link() const;

    /**
     * @brief getCharactersCount
     * @return
     */
    int         getCharactersCount() const;
    /**
     * @brief getCharacterByIndex
     * @param index
     * @return
     */
    Character * getCharacterByIndex(int index) const;
    /**
     * @brief getIndexOfCharacter
     * @param character
     * @return
     */
    int         getIndexOfCharacter(Character * character) const;
    /**
     * @brief getIndexOf
     * @param id
     * @return
     */
    int         getIndexOf(QString id) const;

    /**
     * @brief isGM
     * @return
     */
    bool isGM() const;
    /**
     * @brief getUserVersion
     * @return
     */
    QString getUserVersion();
    /**
     * @brief setUserVersion
     * @param softV
     */
    void setUserVersion(QString softV);

    /**
     * @brief hasFeature
     * @param name
     * @param version
     * @return
     */
    bool hasFeature(const QString & name, quint8 version = 0) const;
    /**
     * @brief setFeature
     * @param name
     * @param version
     */
    void setFeature(const QString & name, quint8 version = 0);

private:
    friend class PlayersList;
    friend class SendFeaturesIterator;

    void addCharacter(Character * character);
    void delCharacter(int index);
    bool searchCharacter(Character * character, int & index) const;
    void setGM(bool value);

private:
    bool m_gameMaster;
    NetworkLink * m_link;
    QList<Character *> m_characters;
    QMap<QString, quint8> m_features;
    QString m_softVersion;
};

#endif // PLAYER_H
