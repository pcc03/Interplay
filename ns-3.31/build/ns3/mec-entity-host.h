/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 TELEMATICS LAB, DEI - Politecnico di Bari
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Nicholas Mirizzi - n.mirizzi1@studenti.poliba.it
 *         Simona Massari - s.massari1@studenti.poliba.it
 */

#ifndef MEC_ENTITY_HOST_H
#define MEC_ENTITY_HOST_H

#include <string.h>
#include <ns3/node.h>
#include <ns3/ptr.h>
#include <map>
#include "mec-entity-meo.h"
#include "mec-entity-bs.h"


namespace ns3 {
class BaseStation;
class MultiaccessEdgeOrchestrator;

class MecHostEntity : public Object
{
public:
  static TypeId GetTypeId (void);

  MecHostEntity ();
  virtual ~MecHostEntity ();

  struct LinkedBs {
    uint64_t bsId;
    double latency;
    Ptr<BaseStation> bs;
  };
  typedef std::vector<LinkedBs>::const_iterator Iterator_b;
  
  struct LinkedHost {
    uint64_t hostId;
    double latency;
    Ptr<MecHostEntity> host;
  };
  typedef std::vector<LinkedHost>::const_iterator Iterator_a;

  uint64_t GetId (void);
  void SetId(uint64_t id);
  double GetUpdatetime(void);
  void SetUpdatetime(int updatetime);
  int GetTotalCount (void);
  void SetTotalCount(int totalcount);
  int GetMisCount (void);
  void SetMisCount(int miscount);
  double GetSecurity (void);
  void SetSecurity(double ss);
    double GetTheta (void);
  void SetTheta(double theta);
    double GetGamma (void);
  void SetGamma(double gamma);
  Ptr<MultiaccessEdgeOrchestrator> GetMeo (void);
  void SetMeo (Ptr<MultiaccessEdgeOrchestrator> meo);
  void AddLinkedBs (uint64_t bsId, double latency, Ptr<BaseStation> bs);
  void AddLinkedHost (uint64_t hostId, double latency, Ptr<MecHostEntity> host);
  LinkedBs FindLinkedBs(uint64_t bsId);
  LinkedHost FindLinkedHost(uint64_t hostId);
  //LinkedHost FindLinkedHost(void);

private:
  uint64_t m_id;
  double m_ss;
  double m_theta;
  double m_gamma;
  int m_totalcount;
  int m_miscount;
  double m_updatetime;
  Ptr<MultiaccessEdgeOrchestrator> m_meo;
  std::vector<LinkedBs> m_linkedBsList;
  std::vector<LinkedHost> m_linkedHostList;//add
  //LinkedHost linkedHost;


};

}

#endif /* MEC_ENTITY_H */

