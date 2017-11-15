#ifndef clas_event_producer_h 
#define clas_event_producer_h 

#include <iostream>

#include "BaseDataObject.h"
#include "BaseDataProducer.h"
#include "CLASEvent.h"
#include "StatusBar.h"

#include "json.hpp"
using json = nlohmann::json; 

// cern root includes for structure of root files 
// that contain this data  
#include "TBranch.h"
#include "TChain.h"

class CLASEventProducer : public BaseDataProducer {
 public:
  CLASEventProducer();
  ~CLASEventProducer();

  bool hasDataObject();
  bool requestsConfiguration();

  // each class can have different options 
  bool setOptions(json j); 

  // each class needs to setup its tree 
  // and add the files after options are set 
  virtual void setupTree();

  // to be over-ridden by specific sub classes 
  virtual CLASEvent *getDataObject();

 protected:
  TChain     *fChain; 
  long int    fCurrentEntry, fMaxEntries;
  int         fFilesToProcess, fFileType; 
  std::string fFilesList, fCurrentFile; 
  StatusBar   fStatusBar; 
  
  void addFile(std::string file);
};

class NT22CLASEventProducer : public CLASEventProducer {
 public:
  NT22CLASEventProducer(); 
  ~NT22CLASEventProducer(); 

  void setupTree();
  CLASEvent *getDataObject();   

 protected:
  const static int BUFFER_SIZE = 16; 

  // in memory data for reading from tree 
  UInt_t          evntid;
  UChar_t         ihel;
  Int_t           corr_hel;
  Float_t         q_l;
  Float_t         tr_time;
  Int_t           gpart;
  Int_t           q[BUFFER_SIZE];   
  Float_t         p[BUFFER_SIZE];   
  Float_t         b[BUFFER_SIZE];   
  Float_t         cx[BUFFER_SIZE];   
  Float_t         cy[BUFFER_SIZE];   
  Float_t         cz[BUFFER_SIZE];   
  Float_t         vz[BUFFER_SIZE];   
  UChar_t         dc_sect[BUFFER_SIZE];
  Float_t         tl1_cx[BUFFER_SIZE]; 
  Float_t         tl1_cy[BUFFER_SIZE]; 
  UChar_t         ec_sect[BUFFER_SIZE];
  Float_t         ec_r[BUFFER_SIZE];  
  Float_t         ec_t[BUFFER_SIZE];  
  Float_t         ec_ei[BUFFER_SIZE]; 
  Float_t         ec_eo[BUFFER_SIZE]; 
  Float_t         etot[BUFFER_SIZE];  
  UChar_t         cc_sect[BUFFER_SIZE];
  Float_t         cc_r[BUFFER_SIZE];   
  Float_t         cc_t[BUFFER_SIZE];   
  UShort_t        nphe[BUFFER_SIZE];   
  Float_t         cc_c2[BUFFER_SIZE];  
  UChar_t         sc_sect[BUFFER_SIZE];
  Float_t         sc_r[BUFFER_SIZE];  
  Float_t         sc_t[BUFFER_SIZE]; 
  Float_t         edep[BUFFER_SIZE]; 
  UChar_t         sc_pd[BUFFER_SIZE];  
  UShort_t        cc_segm[BUFFER_SIZE];
  Float_t         ech_x[BUFFER_SIZE];
  Float_t         ech_y[BUFFER_SIZE];
  Float_t         ech_z[BUFFER_SIZE];
  Float_t         tl1_x[BUFFER_SIZE];
  Float_t         tl1_y[BUFFER_SIZE];
  Float_t         tl1_z[BUFFER_SIZE];
  Float_t         tl3_x[BUFFER_SIZE];
  Float_t         tl3_y[BUFFER_SIZE];
  Float_t         tl3_z[BUFFER_SIZE];
  Float_t         tl3_cx[BUFFER_SIZE];
  Float_t         tl3_cy[BUFFER_SIZE];
  Float_t         tl3_cz[BUFFER_SIZE];
  Int_t           id[BUFFER_SIZE];
  Float_t         vx[BUFFER_SIZE];
  Float_t         vy[BUFFER_SIZE];
  Int_t           nprt;
  Int_t           pidpart[BUFFER_SIZE];
  Float_t         xpart[BUFFER_SIZE];  
  Float_t         ypart[BUFFER_SIZE];  
  Float_t         zpart[BUFFER_SIZE];  
  Float_t         epart[BUFFER_SIZE];  
  Float_t         pxpart[BUFFER_SIZE]; 
  Float_t         pypart[BUFFER_SIZE]; 
  Float_t         pzpart[BUFFER_SIZE]; 
  Float_t         qpart[BUFFER_SIZE];  
  Int_t           Ipart10[BUFFER_SIZE];
  Float_t         Rpart11[BUFFER_SIZE];
  Float_t         Rpart12[BUFFER_SIZE];
  Int_t           Ipart13[BUFFER_SIZE];
  Int_t           mcnentr;
  UChar_t         mcnpart;
  Int_t           mcst[BUFFER_SIZE];  
  Int_t           mcid[BUFFER_SIZE];  
  Int_t           mcpid[BUFFER_SIZE]; 
  Float_t         mctheta[BUFFER_SIZE];
  Float_t         mcphi[BUFFER_SIZE]; 
  Float_t         mcp[BUFFER_SIZE];  
  Float_t         mcm[BUFFER_SIZE];  
  Float_t         mcvx[BUFFER_SIZE];  
  Float_t         mcvy[BUFFER_SIZE];  
  Float_t         mcvz[BUFFER_SIZE];  
  Float_t         mctof[BUFFER_SIZE];   

  // link to root file 
  TBranch        *b_evntid; 
  TBranch        *b_ihel;   
  TBranch        *b_corr_hel;
  TBranch        *b_q_l;   
  TBranch        *b_tr_time;
  TBranch        *b_gpart;
  TBranch        *b_q;   
  TBranch        *b_p;   
  TBranch        *b_b;   
  TBranch        *b_cx;   
  TBranch        *b_cy;   
  TBranch        *b_cz;   
  TBranch        *b_vz;   
  TBranch        *b_dc_sect;
  TBranch        *b_tl1_cx; 
  TBranch        *b_tl1_cy; 
  TBranch        *b_ec_sect;
  TBranch        *b_ec_r;   
  TBranch        *b_ec_t;   
  TBranch        *b_ec_ei;  
  TBranch        *b_ec_eo;  
  TBranch        *b_etot;   
  TBranch        *b_cc_sect;
  TBranch        *b_cc_r;   
  TBranch        *b_cc_t;   
  TBranch        *b_nphe;   
  TBranch        *b_cc_c2;  
  TBranch        *b_sc_sect;
  TBranch        *b_sc_r; 
  TBranch        *b_sc_t; 
  TBranch        *b_edep; 
  TBranch        *b_sc_pd;
  TBranch        *b_cc_segm;
  TBranch        *b_ech_x;
  TBranch        *b_ech_y;
  TBranch        *b_ech_z;
  TBranch        *b_tl1_x;
  TBranch        *b_tl1_y; 
  TBranch        *b_tl1_z; 
  TBranch        *b_tl3_x; 
  TBranch        *b_tl3_y; 
  TBranch        *b_tl3_z; 
  TBranch        *b_tl3_cx;
  TBranch        *b_tl3_cy;
  TBranch        *b_tl3_cz;
  TBranch        *b_id;  
  TBranch        *b_vx;  
  TBranch        *b_vy;  
  TBranch        *b_nprt;   
  TBranch        *b_pidpart;
  TBranch        *b_xpart; 
  TBranch        *b_ypart; 
  TBranch        *b_zpart; 
  TBranch        *b_epart; 
  TBranch        *b_pxpart; 
  TBranch        *b_pypart; 
  TBranch        *b_pzpart; 
  TBranch        *b_qpart;  
  TBranch        *b_Ipart10;
  TBranch        *b_Rpart11;
  TBranch        *b_Rpart12;
  TBranch        *b_Ipart13;
  TBranch        *b_mcnentr;
  TBranch        *b_mcnpart;
  TBranch        *b_mcst;  
  TBranch        *b_mcid;  
  TBranch        *b_mcpid;  
  TBranch        *b_mctheta;
  TBranch        *b_mcphi; 
  TBranch        *b_mcp;   
  TBranch        *b_mcm;   
  TBranch        *b_mcvx;  
  TBranch        *b_mcvy;  
  TBranch        *b_mcvz;  
  TBranch        *b_mctof; 
};

#endif
