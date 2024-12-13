
// 多线程
#include "G4MTRunManager.hh"

// 探测器构建
#include "DetectorConstruction.hh"

// 物理过程
#include "PhysicsList.hh"
#include "FTF_BIC.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysic G4HadronPhysicsFTF_BIC G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut
#include "FTFP_BERT_ATL.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysic G4HadronPhysicsFTFP_BERT_ATL G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut 
#include "FTFP_BERT.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysic G4HadronPhysicsFTFP_BERT G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut        
#include "FTFP_BERT_HP.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysicsHP G4HadronPhysicsFTFP_BERT_HP G4StoppingPhysics G4IonPhysics            
#include "FTFP_BERT_TRV.hh"// G4EmStandardPhysicsGS G4EmExtraPhysics G4DecayPhysics G4HadronHElasticPhysics G4HadronPhysicsFTFP_BERT_TRV G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut
#include "FTFP_INCLXX.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysics G4HadronPhysicsINCLXX G4StoppingPhysics G4IonINCLXXPhysics G4NeutronTrackingCut
#include "FTFP_INCLXX_HP.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysicsHP G4HadronPhysicsINCLXX G4StoppingPhysics G4IonINCLXXPhysics
#include "G4GenericPhysicsList.hh"                    
#include "LBE.hh"// 这个比较复杂 -_-
#include "NuBeam.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysics G4HadronPhysicsNuBeam G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut
#include "QBBC.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysicsXS G4StoppingPhysics G4IonPhysics G4HadronInelasticQBBC G4NeutronTrackingCut
#include "QGS_BIC.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysics G4HadronPhysicsQGS_BIC G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut
#include "QGSP_BERT.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysics G4HadronPhysicsQGSP_BERT G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut
#include "QGSP_BERT_HP.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysicsHP G4HadronPhysicsQGSP_BERT_HP G4StoppingPhysics G4IonPhysics
#include "QGSP_BIC_AllHP.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysicsPHP G4HadronPhysicsQGSP_BIC_AllHP G4StoppingPhysics G4IonPhysicsPHP
#include "QGSP_BIC.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysics G4HadronPhysicsQGSP_BIC G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut
#include "QGSP_BIC_HP.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysicsHP G4HadronPhysicsQGSP_BIC_HP G4StoppingPhysics G4IonPhysics
#include "QGSP_FTFP_BERT.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysics G4HadronPhysicsQGSP_FTFP_BERT G4StoppingPhysics G4IonPhysics G4NeutronTrackingCut
#include "QGSP_INCLXX.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysics G4HadronPhysicsINCLXX G4StoppingPhysics G4IonINCLXXPhysics G4NeutronTrackingCut
#include "QGSP_INCLXX_HP.hh"// G4EmStandardPhysics G4EmExtraPhysics G4DecayPhysics G4HadronElasticPhysicsHP G4HadronPhysicsINCLXX G4StoppingPhysics G4IonINCLXXPhysics
#include "Shielding.hh"// 这个比较复杂,分好几种情况

#include "G4ParticleHPManager.hh"

// Action管理
#include "ActionInitialization.hh"

// 图形界面与交互接口
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

// 自定义纲图
#include "G4NuclearLevelData.hh"

// ROOT
#include "TROOT.h"

#include "Randomize.hh"

#include <unistd.h>  // access 函数
#include <ctime>    // time 函数

using namespace std;

int main(int argc,char** argv)
{
    if (argc > 3){
        printf("ERROR: More than 2 parameters");
        exit(EXIT_FAILURE);
    }
    
    ROOT::EnableThreadSafety(); // 这一行非常重要，少了程序就崩溃
    
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    G4Random::setTheSeed(time(NULL));

    // 创建多线程管理，读取第 2 个参数作为线程数，默认线程数 2
    G4int nThreads = 0;// 线程数
    if (argc == 3) nThreads = atoi(argv[2]);
    if (nThreads == 0) nThreads = 2;
    G4MTRunManager* mtrunManager = new G4MTRunManager;
    mtrunManager->SetNumberOfThreads(nThreads);

    // 构建探测器
    mtrunManager->SetUserInitialization(new DetectorConstruction());

    // 物理过程：可选自定义的(PhysicsList)、或已封装好的(FTFP_BERT_HP)物理过程类
    G4VModularPhysicsList* physicsList = new PhysicsList();
    mtrunManager->SetUserInitialization(physicsList);
    // mtrunManager->SetUserInitialization(new FTFP_BERT_HP());
  
    // 初始化 action
    mtrunManager->SetUserInitialization(new ActionInitialization());
    
    // 初始化 G4 内核
    mtrunManager->Initialize();
    
    // 添加自定义纲图（去掉65Ga的1847和67Ga的1714跃迁）
    G4NuclearLevelData::GetInstance()->AddPrivateData(31, 65, "../../anaGa65/z31.a65");
    G4NuclearLevelData::GetInstance()->AddPrivateData(31, 67, "../../anaGa67/z31.a67");

    G4VisManager* visManager = 0;
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    // 命令行模式
    if (argc == 1){
        G4UIsession* session = new G4UIterminal(new G4UItcsh);
        session->SessionStart();
        delete session;
    }
    else{
        G4String commandopt = argv[1];
        G4int eventnum = atoi(argv[1]);
        
        // 自动运行 run
        if (eventnum > 0){
            char command [100];
            sprintf(command,"/run/beamOn %d",eventnum);
            UImanager->ApplyCommand(command);
            UImanager->ApplyCommand("exit");
        }
        
        // 图形界面模式，参数为图形界面脚本文件路径
        else if (commandopt == "-v"){
            visManager = new G4VisExecutive;
            visManager->Initialize();

            G4UIExecutive* ui = new G4UIExecutive(argc, argv);
            UImanager->ApplyCommand("/control/execute scripts/vis.mac");
            ui->SessionStart();
            delete ui;
        }
        
        // 脚本模式，参数应为脚本文件路径
        else {
            G4String command = "/control/execute ";
            UImanager->ApplyCommand(command + commandopt);
        }
    }
    
    if(visManager != 0)
        delete visManager;
    delete mtrunManager;
/*
    // 合并多线程产生的多个 ROOT 文件
    if (access("g4raw_t0.root",F_OK) == 0){
        char commandhadd[1000],commandrm[1000];
        strcpy(commandhadd,"hadd -f ../../root/g4raw.root");
        strcpy(commandrm,"rm");
        for (int i=0; i<nThreads; i++){
            char buf[20];
            sprintf(buf, " g4raw_t%d.root", i);
            strcat(commandhadd,buf);
            strcat(commandrm,buf);
        }
        system(commandhadd);
        system(commandrm);
    }
*/
    // 不合并 ROOT 文件，仅移动
    system("mv g4raw_*.root ../../root/");
    return 0;
}
