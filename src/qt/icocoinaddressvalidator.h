// Copyright (c) 2011-2014 The Icocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ICOCOIN_QT_ICOCOINADDRESSVALIDATOR_H
#define ICOCOIN_QT_ICOCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class IcocoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit IcocoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Icocoin address widget validator, checks for a valid icocoin address.
 */
class IcocoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit IcocoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // ICOCOIN_QT_ICOCOINADDRESSVALIDATOR_H
