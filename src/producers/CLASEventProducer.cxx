#ifndef clas_event_producer_cxx
#define clas_event_producer_cxx 

#include <iostream>
#include <fstream>

#include "BaseDataObject.h"
#include "BaseDataProducer.h"
#include "CLASEvent.h"
#include "CLASEventProducer.h"

#include "json.hpp"
using json = nlohmann::json; 

// cern root includes for structure of root files 
// that contain this data  
#include "TBranch.h"
#include "TChain.h"
#include "TFile.h"

CLASEventProducer::CLASEventProducer(){
  fId = "CLASEventProducer";

  fMaxEntries     = 0; 
  fCurrentEntry   = 0;
  fFilesToProcess = 0; 
}

CLASEventProducer::~CLASEventProducer(){
  delete fChain;
}

bool CLASEventProducer::hasDataObject(){
  if(fCurrentEntry <= fMaxEntries){

    if(fCurrentEntry%10000 == 0){
      fStatusBar.PrintStatus(fCurrentEntry, fMaxEntries); 
    }

    fCurrentEntry++; 
    return true; 
  }

  return false; 
}

bool CLASEventProducer::requestsConfiguration(){
  
  std::string file(fChain->GetFile()->GetName()); 
  if(fCurrentFile != file){
    fCurrentFile = file; 
    return true; 
  }

  return false;
}

bool CLASEventProducer::setOptions(json j){

  if(j.count("n_files") != 1 || j.count("file_list") != 1 || j.count("data_type") != 1){
    std::cerr << "[CLASEventProducer::setOptions] FATAL: Options n_files, file_list, and data_type need to be supplied for this class to do setup." << std::endl; 
    exit(0);
  }

  // setting local variables 
  fFilesList = j.at("file_list").get<std::string>();
  fFilesToProcess = j.at("n_files").get<int>(); 
  fFileType = j.at("data_type").get<int>();

  setupTree(); 

  return true;
} 

void CLASEventProducer::setupTree(){
  std::cout << "[CLASEventProducer::setupTree] Base method called, check your implementation and ensure that your producer has setupTree() method. " << std::endl; 
}

CLASEvent * CLASEventProducer::getDataObject(){
  return new CLASEvent(); 
}
  
void CLASEventProducer::addFile(std::string file){
  fChain->AddFile(file.c_str());
  std::cout << "[CLASEventProvider::addFile] Adding file to producer: "  << file << std::endl; 
}

NT22CLASEventProducer::NT22CLASEventProducer(){
  setId("NT22CLASEventProducer"); 

  fChain = new TChain("h22"); 
}

NT22CLASEventProducer::~NT22CLASEventProducer(){
}

void NT22CLASEventProducer::setupTree(){

  // adding files 
  if(fFilesToProcess < 1){
    std::cerr << "[NT22CLASEventProvider::setupTree] The number of files to process was 0 on setup, dying. " << std::endl;
    exit(0); 
  } 
  
  std::ifstream inputFile; 
  inputFile.open(fFilesList);

  if(inputFile.is_open()){
    for(int ifile=0; ifile<fFilesToProcess; ifile++){
      std::string file;
      inputFile >> file; 
      addFile(file);
    }
  } 
  else {
    std::cerr << "[NT22CLASEventProvider::setupTree] Trouble opening file list " << fFilesList << " dying. " << std::endl; 
    exit(0);
  }
  
  inputFile.close(); 

  // setting max entries to length of tree
  fCurrentFile = std::string(fChain->GetFile()->GetName()); 
  fMaxEntries = fChain->GetEntries(); 

  // required setup 
  fChain->SetBranchAddress("evntid", &evntid, &b_evntid);
  fChain->SetBranchAddress("ihel", &ihel, &b_ihel);
  fChain->SetBranchAddress("corr_hel", &corr_hel, &b_corr_hel);
  fChain->SetBranchAddress("q_l", &q_l, &b_q_l);
  fChain->SetBranchAddress("gpart", &gpart, &b_gpart);
  fChain->SetBranchAddress("q", q, &b_q);
  fChain->SetBranchAddress("p", p, &b_p);
  fChain->SetBranchAddress("b", b, &b_b);
  fChain->SetBranchAddress("id", id, &b_id);
  fChain->SetBranchAddress("cx", cx, &b_cx);
  fChain->SetBranchAddress("cy", cy, &b_cy);
  fChain->SetBranchAddress("cz", cz, &b_cz);
  fChain->SetBranchAddress("vz", vz, &b_vz);
  fChain->SetBranchAddress("dc_sect", dc_sect, &b_dc_sect);
  fChain->SetBranchAddress("tl1_cx", tl1_cx, &b_tl1_cx);
  fChain->SetBranchAddress("tl1_cy", tl1_cy, &b_tl1_cy);
  fChain->SetBranchAddress("ec_sect", ec_sect, &b_ec_sect);
  fChain->SetBranchAddress("ec_r", ec_r, &b_ec_r);
  fChain->SetBranchAddress("ec_t", ec_t, &b_ec_t);
  fChain->SetBranchAddress("ec_ei", ec_ei, &b_ec_ei);
  fChain->SetBranchAddress("ec_eo", ec_eo, &b_ec_eo);
  fChain->SetBranchAddress("etot", etot, &b_etot);
  fChain->SetBranchAddress("cc_sect", cc_sect, &b_cc_sect);
  fChain->SetBranchAddress("cc_r", cc_r, &b_cc_r);
  fChain->SetBranchAddress("cc_t", cc_t, &b_cc_t);
  fChain->SetBranchAddress("nphe", nphe, &b_nphe);
  fChain->SetBranchAddress("cc_c2", cc_c2, &b_cc_c2);
  fChain->SetBranchAddress("sc_sect", sc_sect, &b_sc_sect);
  fChain->SetBranchAddress("sc_r", sc_r, &b_sc_r);
  fChain->SetBranchAddress("sc_t", sc_t, &b_sc_t);
  fChain->SetBranchAddress("edep", edep, &b_edep);
  fChain->SetBranchAddress("sc_pd", sc_pd, &b_sc_pd);
  fChain->SetBranchAddress("cc_segm", cc_segm, &b_cc_segm);
  fChain->SetBranchAddress("ech_x", ech_x, &b_ech_x);
  fChain->SetBranchAddress("ech_y", ech_y, &b_ech_y);
  fChain->SetBranchAddress("ech_z", ech_z, &b_ech_z);
  fChain->SetBranchAddress("tl1_x", tl1_x, &b_tl1_x);
  fChain->SetBranchAddress("tl1_y", tl1_y, &b_tl1_y);
  fChain->SetBranchAddress("tl1_z", tl1_z, &b_tl1_z);
  fChain->SetBranchAddress("tl3_x", tl3_x, &b_tl3_x);
  fChain->SetBranchAddress("tl3_y", tl3_y, &b_tl3_y);
  fChain->SetBranchAddress("tl3_z", tl3_z, &b_tl3_z);
  fChain->SetBranchAddress("tl3_cx", tl3_cx, &b_tl3_cx);
  fChain->SetBranchAddress("tl3_cy", tl3_cy, &b_tl3_cy);
  fChain->SetBranchAddress("tl3_cz", tl3_cz, &b_tl3_cz);
  fChain->SetBranchAddress("vx", vx, &b_vx);
  fChain->SetBranchAddress("vy", vy, &b_vy);

  if (fFileType == 1){
    fChain->SetBranchAddress("mcnentr", &mcnentr, &b_mcnentr);
    fChain->SetBranchAddress("mcnpart", &mcnpart, &b_mcnpart);
    fChain->SetBranchAddress("mcst", mcst, &b_mcst);
    fChain->SetBranchAddress("mcid", mcid, &b_mcid);
    fChain->SetBranchAddress("mcpid", mcpid, &b_mcpid);
    fChain->SetBranchAddress("mctheta", mctheta, &b_mctheta);
    fChain->SetBranchAddress("mcphi", mcphi, &b_mcphi);
    fChain->SetBranchAddress("mcp", mcp, &b_mcp);
    fChain->SetBranchAddress("mcm", mcm, &b_mcm);
    fChain->SetBranchAddress("mcvx", mcvx, &b_mcvx);
    fChain->SetBranchAddress("mcvy", mcvy, &b_mcvy);
    fChain->SetBranchAddress("mcvz", mcvz, &b_mcvz);
    fChain->SetBranchAddress("mctof", mctof, &b_mctof);
  }

}

CLASEvent * NT22CLASEventProducer::getDataObject(){

  fChain->GetEntry(fCurrentEntry);

  CLASEvent *event = new CLASEvent(); 

  ScalarBank *scalar = new ScalarBank();
  scalar->event_id   = evntid; 
  scalar->gpart      = gpart; 
  scalar->q_l        = q_l; 
  scalar->helicity   = corr_hel; 
  scalar->start_time = tr_time; 
  event->addMetaBank(bank_t::scalar, scalar); 

  for(int itrack=0; itrack<gpart; itrack++){
    
    CLASTrack *track = new CLASTrack(); 
    
    CCBank *cc         = new CCBank(); 
    DCBank *dc         = new DCBank(); 
    ECBank *ec         = new ECBank(); 
    PartBank *part     = new PartBank(); 
    TOFBank *tof       = new TOFBank(); 
    
    part->p    = p[itrack]; 
    part->q    = (int) q[itrack]; 
    part->vx   = vx[itrack]; 
    part->vy   = vy[itrack]; 
    part->vz   = vz[itrack]; 
    part->etot = etot[itrack]; 

    cc->nphe    = (int) nphe[itrack]; 
    cc->segment = (int) cc_segm[itrack]; 
    cc->sector  = (int) cc_sect[itrack];
    cc->chi2    = cc_c2[itrack]; 
    cc->path    = cc_r[itrack];
    cc->time    = cc_t[itrack];

    dc->x_r1 = tl1_x[itrack]; 
    dc->y_r1 = tl1_y[itrack]; 
    dc->z_r1 = tl1_z[itrack]; 
    dc->x_r3 = tl3_x[itrack]; 
    dc->y_r3 = tl3_y[itrack]; 
    dc->z_r3 = tl3_z[itrack]; 
    dc->cx_r1 = tl1_cx[itrack];
    dc->cy_r1 = tl1_cy[itrack];
    dc->cx_r3 = tl3_cx[itrack];
    dc->cy_r3 = tl3_cy[itrack];
    dc->cz_r3 = tl3_cz[itrack];
    dc->sector = (int) dc_sect[itrack];

    ec->edep_inner = ec_ei[itrack]; 
    ec->edep_outer = ec_eo[itrack]; 
    ec->edep         = edep[itrack]; 
    ec->x            = ech_x[itrack];
    ec->y            = ech_y[itrack];
    ec->z            = ech_z[itrack];
    ec->path         = ec_r[itrack]; 
    ec->time         = ec_t[itrack];
    ec->sector       = (int) ec_sect[itrack];

    tof->path        = sc_r[itrack];
    tof->time        = sc_t[itrack];
    tof->sector      = (int) sc_sect[itrack]; 
    tof->paddle      = (int) sc_pd[itrack];

    track->addBank(bank_t::cc,   cc);
    track->addBank(bank_t::dc,   dc);
    track->addBank(bank_t::ec,   ec);
    track->addBank(bank_t::part, part);
    track->addBank(bank_t::tof,  tof);

    event->addTrack(track);
  }

  if(fFileType == 1){
    for(int ipart=0; ipart<mcnentr; ipart++){
      MCBank *bank = new MCBank(); 

      bank->pid   = mcid[ipart]; 
      bank->p     = mcp[ipart]; 
      bank->mass  = mcm[ipart]; 
      bank->vx    = mcvx[ipart];
      bank->vy    = mcvy[ipart];
      bank->vz    = mcvz[ipart];
      bank->theta = mctheta[ipart];
      bank->phi   = mcphi[ipart];
      bank->tof   = mctof[ipart];

      event->addMCBank(bank); 
    }
  }

  return event; 
}   

#endif
