// HV.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 5月 17 15:21:12 2021 (+0800)
// Last-Updated: 二 5月 18 11:11:43 2021 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 43
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

int main(int argc, char *argv[])
{
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

  strcpy(arg, "222.29.111.104");
	
  ret = CAENHV_InitSystem((CAENHV_SYSTEM_TYPE_t)sysType, link, arg, userName, passwd, &sysHndl);
  printf("\nCAENHV_InitSystem: %s (num. %d)\n\n", CAENHV_GetError(sysHndl), ret);


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
  char  (*listNameCh)[MAX_CH_NAME];
  // char ** listNameCh = (char *) malloc (sizeof(char)* 4);
  // for(int i = 0 ; i< 4 ; i ++)
  //   {
  //     listNameCh[i] = (char *) malloc(sizeof(char)* MAX_CH_NAME);
  //   }
	
  Slot = 0;
  NrOfCh_ = 4;
  for(int  n = 0; n < NrOfCh_; n++ )
    {	
      listaCh[n] = n;
    }
  listNameCh = (char*)malloc(NrOfCh_*MAX_CH_NAME);

	
	
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

	
  strcpy(ChName, "LaBr3_0");
  ret = CAENHV_SetChName(sysHndl, Slot, NrOfCh_, listaCh, ChName);
  printf("CAENHV_SetChName: %s (num. %d)\n\n", CAENHV_GetError(sysHndl), ret);


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
