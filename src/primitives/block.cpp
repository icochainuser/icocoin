// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Icocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/block.h"

#include "hash.h"
#include "tinyformat.h"
#include "utilstrencodings.h"
#include "crypto/common.h"

uint256 CBlockHeader::GetHash() const
{
    return ComputePowHash(nNonce);
}

uint256 CBlockHeader::ComputePowHash(uint32_t nNonce) const
{
    CScryptHash256Pow hasher;
    CDataStream ss(SER_NETWORK, PROTOCOL_VERSION);
    ss << *this;
    assert(ss.size() == 80);
    hasher.Write((unsigned char*)&ss[0], 76);
    uint256 powHash;
    CScryptHash256Pow(hasher).Write((unsigned char*)&nNonce, 4).Finalize((unsigned char*)&powHash);
    return powHash;
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=%d, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size());
    for (unsigned int i = 0; i < vtx.size(); i++)
    {
        s << "  " << vtx[i].ToString() << "\n";
    }
    return s.str();
}
