#ifndef clas_event_cxx
#define clas_event_cxx 

#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "BaseDataObject.h"
#include "CLASEvent.h"

CLASBank::CLASBank(){
  fId = bank_t::undefined; 
}

CLASBank::~CLASBank(){
}

CCBank::CCBank(){
  fId = bank_t::cc; 
}

CCBank::~CCBank(){
}

DCBank::DCBank(){
  fId = bank_t::dc; 
}

DCBank::~DCBank(){
}

ECBank::ECBank(){
  fId = bank_t::ec; 
}

ECBank::~ECBank(){
}

ICBank::ICBank(){
  fId = bank_t::ic; 
}

ICBank::~ICBank(){
}

PartBank::PartBank(){
  fId = bank_t::part; 
}

PartBank::~PartBank(){
}

ScalarBank::ScalarBank(){
  fId = bank_t::scalar; 
}

ScalarBank::~ScalarBank(){
}

TOFBank::TOFBank(){
  fId = bank_t::tof; 
}

TOFBank::~TOFBank(){
}

CLASTrack::CLASTrack(){
}

CLASTrack::~CLASTrack(){
  fBanks.clear(); 
}

bool CLASTrack::hasBank(int bankId){
  return fBanks.count(bankId); 
}

CLASBank* CLASTrack::getBank(int bankId){
  return fBanks[bankId].get();
}
  
CLASEvent::CLASEvent(){
}
CLASEvent::~CLASEvent(){
  fMetaBanks.clear();
  fTracks.clear(); 
}

bool CLASEvent::hasMetaBank(int bankId) const {
  return fMetaBanks.count(bankId);
}

CLASBank * CLASEvent::getMetaBank(int bankId){
  return fMetaBanks[bankId].get();
} 

CLASTrack * CLASEvent::getTrack(int index){
  return fTracks[index].get();
}

#endif
