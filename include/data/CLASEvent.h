#ifndef clas_event_h 
#define clas_event_h 

#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "BaseDataObject.h"

enum bank_t {
  undefined, 
  cc,
  dc,
  ec,
  ic,
  part, 
  scalar,
  tof
};

class CLASBank {
 public:
  CLASBank(); 
  ~CLASBank();  

  int getId() const {
    return fId; 
  }

 protected:
  int fId; 
};

class CCBank : public CLASBank {
 public:
  CCBank(); 
  ~CCBank(); 

  int nphe, sector, segment; 
  float chi2, path, time, theta; 
};

class DCBank : public CLASBank {
 public:
  DCBank(); 
  ~DCBank(); 

  int sector; 
  float x_r1_rot, y_r1_rot; 
  float x_r1, y_r1, z_r1; 
  float x_r3, y_r3, z_r3;
  float cx_r1, cy_r1; 
  float cx_r3, cy_r3, cz_r3; 
};

class ECBank : public CLASBank {
 public:
  ECBank();
  ~ECBank();

  int sector; 
  float x, y, z; 
  float u, v, w; 
  float edep_inner, edep_outer, edep;
  float path, time; 
};

class ICBank : public CLASBank {
 public:
  ICBank(); 
  ~ICBank(); 

  float x, y; 
};

class PartBank : public CLASBank {
 public:
  PartBank(); 
  ~PartBank(); 

  int q, pid; 
  float p, beta, etot; 
  float vx, vy, vz; 
  float theta, phi, relative_phi; 
};

class ScalarBank : public CLASBank {
 public:
  ScalarBank(); 
  ~ScalarBank(); 
  
  int event_id, helicity, gpart;
  float start_time, q_l; 

};

class TOFBank : public CLASBank {
 public:
  TOFBank(); 
  ~TOFBank(); 

  int sector, paddle; 
  float path, time; 
  
};

class CLASTrack {
 public:
  CLASTrack(); 
  ~CLASTrack(); 

  bool hasBank(int bankId); 
  CLASBank* getBank(int bankId);
  
 protected:
  std::map<int, std::unique_ptr<CLASBank> > fBanks; 
  
};

class CLASEvent : public BaseDataObject {
 public:
  CLASEvent(); 
  ~CLASEvent(); 

  int getNumberOfTracks() const {
    return fTracks.size(); 
  }
 
  bool hasMetaBank(int bankId) const;
  CLASBank  *getMetaBank(int bankId); 
  CLASTrack *getTrack(int index);   

 protected:
  std::map<int, std::unique_ptr<CLASBank> > fMetaBanks; 
  std::vector< std::unique_ptr<CLASTrack> >  fTracks; 
};

#endif
