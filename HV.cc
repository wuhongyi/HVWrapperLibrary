// HV.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 5月 17 15:21:12 2021 (+0800)
// Last-Updated: 五 6月 18 19:47:09 2021 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 66
// URL: http://wuhongyi.cn 

// g++ -DUNIX -DLINUX HV.cc -lcaenhvwrapper -o 123

#include "CAENHVWrapper.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// InitSystem             ok
// DeinitSystem           ok
// ExecComm 
// GetBdParam 
// GetBdParamInfo 
// GetBdParamProp
// GetChName              ok
// GetChParam             ok
// GetChParamInfo
// GetChParamProp
// GetCrateMap            ok
// GetExecCommList
// GetSysProp
// GetSysPropInfo
// GetSysPropList
// SetBdParam
// SetChName              ok
// SetChParam             ok
// SetSysProp
// TestBdPresence
// SubscribeBoardParams
// SubscribeChannelParams
// SubscribeSystemParams
// UnSubscribeBoardParams
// UnSubscribeChannelParams
// UnSubscribeSystemParams
// Event Data Items
// FreeEventData
// GetEventData 


int main(int argc, char *argv[])
{
  // 对单通道的设置
  // int err = CAENHV_SetChParam(handle, slot, "V0Set", 1, &channel, &val);

  
  char *SoftRel;
  SoftRel = CAENHVLibSwRel();
  printf("\nCAEN HV Wrapper Library Release: %s", SoftRel);

  
  char          arg[30], userName[30], passwd[30];
  int           link;
  int           sysHndl=-1;
  int           sysType=-1;
  CAENHVRESULT  ret;

  sysType= N1470;
  link = LINKTYPE_TCPIP;
  strcpy(userName, "admin");
  strcpy(passwd, "admin");

  strcpy(arg, "222.29.111.187");
	
  ret = CAENHV_InitSystem((CAENHV_SYSTEM_TYPE_t)sysType, link, arg, userName, passwd, &sysHndl);
  printf("\nCAENHV_InitSystem: %s (num. %d)\n\n", CAENHV_GetError(sysHndl), ret);
  std::cout<<"Handle: "<<sysHndl<<std::endl;

  unsigned short	NrOfSl, *SerNumList, *NrOfCh;
  char			*ModelList, *DescriptionList;
  unsigned char	*FmwRelMinList, *FmwRelMaxList;

  ret = CAENHV_GetCrateMap(sysHndl, &NrOfSl, &NrOfCh, &ModelList, &DescriptionList, &SerNumList, &FmwRelMinList, &FmwRelMaxList);
  if( ret != CAENHV_OK )
    {
      printf("CAENHV_GetCrateMap: %s (num. %d)\n\n", CAENHV_GetError(sysHndl), ret);
    }

  std::cout<<"0:"<<NrOfSl<<std::endl;//数量
  std::cout<<"1:"<<NrOfCh[0]<<std::endl;
  std::cout<<"2:"<<ModelList<<std::endl;//型号
  std::cout<<"3:"<<DescriptionList[0]<<std::endl;//no
  std::cout<<"4:"<<SerNumList[0]<<std::endl;
  std::cout<<"5:"<<FmwRelMinList[0]<<std::endl;//no
  std::cout<<"6:"<<FmwRelMaxList[0]<<std::endl;//no

  CAENHV_Free(SerNumList);
  CAENHV_Free(ModelList);
  CAENHV_Free(DescriptionList);
  CAENHV_Free(FmwRelMinList);
  CAENHV_Free(FmwRelMaxList);
  CAENHV_Free(NrOfCh);



  
  std::cout<<"=========="<<std::endl;

	
  unsigned short Slot, NrOfCh_, listaCh[2048];
  char ChName[20];
  char listNameCh[4][MAX_CH_NAME];
	
  Slot = 0;
  NrOfCh_ = 4;
  for(int  n = 0; n < NrOfCh_; n++ )
    {	
      listaCh[n] = n;
    }

	
  ret = CAENHV_GetChName(sysHndl, Slot, NrOfCh_, listaCh, listNameCh);
  if( ret != CAENHV_OK )
    {
      printf("CAENHV_GetChName: %s (num. %d)\n\n", CAENHV_GetError(sysHndl), ret);
    }
  else
    {
      printf("CHANNEL NAME\n");    
      for(int n = 0; n < NrOfCh_; n++ )
	printf("Channel n. %d: %s\n", listaCh[n], listNameCh[n]);
    }

	
  // strcpy(ChName, "LaBr3_0");
  // ret = CAENHV_SetChName(sysHndl, Slot, NrOfCh_, listaCh, ChName);
  // printf("CAENHV_SetChName: %s (num. %d)\n\n", CAENHV_GetError(sysHndl), ret);


  // ret = CAENHV_GetChName(sysHndl, Slot, NrOfCh_, listaCh, listNameCh);
  // if( ret != CAENHV_OK )
  //   {
  //     printf("CAENHV_GetChName: %s (num. %d)\n\n", CAENHV_GetError(sysHndl), ret);
  //   }
  // else
  //   {
  //     printf("CHANNEL NAME\n");    
  //     for(int n = 0; n < NrOfCh_; n++ )
  // 	printf("Channel n. %d: %s\n", listaCh[n], listNameCh[n]);
  //   }


  // Set/GetChParam
  // V0Set    Float
  // I0Set    Float
  // V1Set    Float
  // I1Set    Float
  // Rup      Float
  // RDWn     Float
  // Trip     Float
  // SVMax    Float
  // Vmon     Float
  // Imon     Float
  // Status   Unsigned (Bitfield)
  // Pw       Unsigned (Boolean)
  // Pon      Unsigned (Boolean)
  // PDwn     Unsigned (Boolean)
  // TripInt  Unsigned
  // TripExt  Unsigned

  char sw[30];
  ret = CAENHV_GetSysProp(sysHndl, "SwRelease", sw);
  std::cout<<"SwRelease: "<<sw<<std::endl;

  unsigned int vali[4];
  float valf[4];
  
  for(int  n = 0; n < NrOfCh_; n++ )
    {	
      listaCh[n] = n;
    }

  ret = CAENHV_GetChParam(sysHndl, Slot, "Status", NrOfCh_, listaCh, vali);
  for(int  n = 0; n < NrOfCh_; n++ ) std::cout<<"ch: "<<n<<"  Status: "<<vali[n]<<std::endl;
  ret = CAENHV_GetChParam(sysHndl, Slot, "Pw", NrOfCh_, listaCh, vali);
  for(int  n = 0; n < NrOfCh_; n++ ) std::cout<<"ch: "<<n<<"  Power: "<<vali[n]<<std::endl;

  ret = CAENHV_GetChParam(sysHndl, Slot, "V0Set", NrOfCh_, listaCh, valf);
  for(int  n = 0; n < NrOfCh_; n++ ) std::cout<<"ch: "<<n<<"  Voltage Set: "<<valf[n]<<std::endl;
  ret = CAENHV_GetChParam(sysHndl, Slot, "I0Set", NrOfCh_, listaCh, valf);
  for(int  n = 0; n < NrOfCh_; n++ ) std::cout<<"ch: "<<n<<"  Current Set: "<<valf[n]<<std::endl;

  ret = CAENHV_GetChParam(sysHndl, Slot, "VMon", NrOfCh_, listaCh, valf);
  for(int  n = 0; n < NrOfCh_; n++ ) std::cout<<"ch: "<<n<<"  Voltage: "<<valf[n]<<std::endl;
  // ret = CAENHV_GetChParam(sysHndl, Slot, "IMon", NrOfCh_, listaCh, valf);
  // for(int  n = 0; n < NrOfCh_; n++ ) std::cout<<"ch: "<<n<<"  Current: "<<valf[n]<<std::endl;  
  
  // ret = CAENHV_GetChParam(sysHndl, Slot, "Rup", NrOfCh_, listaCh, valf);
  // for(int  n = 0; n < NrOfCh_; n++ ) std::cout<<"ch: "<<n<<"  Rup: "<<valf[n]<<std::endl;
  // ret = CAENHV_GetChParam(sysHndl, Slot, "RDWn", NrOfCh_, listaCh, valf);
  // for(int  n = 0; n < NrOfCh_; n++ ) std::cout<<"ch: "<<n<<"  RDWn: "<<valf[n]<<std::endl;

  
  
  // vali[0] = 0;
  // vali[1] = 0;
  // vali[2] = 0;
  // vali[3] = 0;
  // ret = CAENHV_SetChParam(sysHndl, Slot, "Pw", NrOfCh_, listaCh, vali);


  
  // valf[0] = 100;
  // valf[1] = 500;
  // valf[2] = 750;
  // valf[3] = 1000;
  // ret = CAENHV_SetChParam(sysHndl, Slot, "V0Set", NrOfCh_, listaCh, valf);





  
  std::cout<<"=========="<<std::endl;	

  ret = CAENHV_DeinitSystem(sysHndl);
  if( ret == CAENHV_OK )
    printf("CAENHV_DeinitSystem: Connection closed (num. %d)\n\n", ret);
  else
    printf("CAENHV_DeinitSystem: %s (num. %d)\n\n", CAENHV_GetError(sysHndl), ret);
	
  
  return 0;
}

// 
// HV.cc ends here
