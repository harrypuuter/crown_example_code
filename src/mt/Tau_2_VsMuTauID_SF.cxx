#include "ROOT/RDataFrame.hxx"
#include "ROOT/RDFHelpers.hxx"
#include "RooTrace.h"
#include "TStopwatch.h"
#include <ROOT/RLogger.hxx>
#include "include/utility/Logger.hxx"
#include <TFile.h>
#include <TMap.h>
#include <filesystem>
#include <TObjString.h>
#include <TTree.h>
#include <TVector.h>
#include "onnxruntime_cxx_api.h"
#include <regex>
#include <string>
#include "include/utility/OnnxSessionManager.hxx"
#include "include/utility/CorrectionManager.hxx"
#include "include/genparticles.hxx"
#include "include/htxs.hxx"
#include "include/jets.hxx"
#include "include/lorentzvectors.hxx"
#include "include/met.hxx"
#include "include/ml.hxx"
#include "include/metfilter.hxx"
#include "include/pairselection.hxx"
#include "include/tripleselection.hxx"
#include "include/physicsobjects.hxx"
#include "include/quantities.hxx"
#include "include/reweighting.hxx"
#include "include/scalefactors.hxx"
#include "include/topreco.hxx"
#include "include/triggers.hxx"
#include "include/fakefactors.hxx"
ROOT::RDF::RNode Tau_2_VsMuTauID_SF_mt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = scalefactor::tau::id_vsMu(df0, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df2 = scalefactor::tau::id_vsMu(df1, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df3 = scalefactor::tau::id_vsMu(df2, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df4 = scalefactor::tau::id_vsMu(df3, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df5 = scalefactor::tau::id_vsMu(df4, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "down", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel5Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df6 = scalefactor::tau::id_vsMu(df5, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "down", "id_wgt_tau_vsMu_Loose_2__vsMuWheel5Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df7 = scalefactor::tau::id_vsMu(df6, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "down", "id_wgt_tau_vsMu_Medium_2__vsMuWheel5Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df8 = scalefactor::tau::id_vsMu(df7, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "down", "id_wgt_tau_vsMu_Tight_2__vsMuWheel5Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df9 = scalefactor::tau::id_vsMu(df8, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "down", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel2Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df10 = scalefactor::tau::id_vsMu(df9, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "down", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__vsMuWheel2Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df11 = scalefactor::tau::id_vsMu(df10, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "down", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__vsMuWheel2Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df12 = scalefactor::tau::id_vsMu(df11, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "down", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__vsMuWheel2Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df13 = scalefactor::tau::id_vsMu(df12, correctionManager, "eta_2__tauEs3prong1pizeroDown", "tau_decaymode_2__tauEs3prong1pizeroDown", "tau_gen_match_2__tauEs3prong1pizeroDown", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__tauEs3prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df14 = scalefactor::tau::id_vsMu(df13, correctionManager, "eta_2__tauEs3prong1pizeroDown", "tau_decaymode_2__tauEs3prong1pizeroDown", "tau_gen_match_2__tauEs3prong1pizeroDown", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__tauEs3prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df15 = scalefactor::tau::id_vsMu(df14, correctionManager, "eta_2__tauEs3prong1pizeroDown", "tau_decaymode_2__tauEs3prong1pizeroDown", "tau_gen_match_2__tauEs3prong1pizeroDown", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__tauEs3prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df16 = scalefactor::tau::id_vsMu(df15, correctionManager, "eta_2__tauEs3prong1pizeroDown", "tau_decaymode_2__tauEs3prong1pizeroDown", "tau_gen_match_2__tauEs3prong1pizeroDown", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__tauEs3prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df17 = scalefactor::tau::id_vsMu(df16, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "up", "nom", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel4Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df18 = scalefactor::tau::id_vsMu(df17, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "nom", "up", "nom", "id_wgt_tau_vsMu_Loose_2__vsMuWheel4Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df19 = scalefactor::tau::id_vsMu(df18, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "nom", "up", "nom", "id_wgt_tau_vsMu_Medium_2__vsMuWheel4Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df20 = scalefactor::tau::id_vsMu(df19, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "nom", "up", "nom", "id_wgt_tau_vsMu_Tight_2__vsMuWheel4Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df21 = scalefactor::tau::id_vsMu(df20, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "down", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel1Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df22 = scalefactor::tau::id_vsMu(df21, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "down", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__vsMuWheel1Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df23 = scalefactor::tau::id_vsMu(df22, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "down", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__vsMuWheel1Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df24 = scalefactor::tau::id_vsMu(df23, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "down", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__vsMuWheel1Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df25 = scalefactor::tau::id_vsMu(df24, correctionManager, "eta_2__tauEs1prong0pizeroDown", "tau_decaymode_2__tauEs1prong0pizeroDown", "tau_gen_match_2__tauEs1prong0pizeroDown", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__tauEs1prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df26 = scalefactor::tau::id_vsMu(df25, correctionManager, "eta_2__tauEs1prong0pizeroDown", "tau_decaymode_2__tauEs1prong0pizeroDown", "tau_gen_match_2__tauEs1prong0pizeroDown", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__tauEs1prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df27 = scalefactor::tau::id_vsMu(df26, correctionManager, "eta_2__tauEs1prong0pizeroDown", "tau_decaymode_2__tauEs1prong0pizeroDown", "tau_gen_match_2__tauEs1prong0pizeroDown", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__tauEs1prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df28 = scalefactor::tau::id_vsMu(df27, correctionManager, "eta_2__tauEs1prong0pizeroDown", "tau_decaymode_2__tauEs1prong0pizeroDown", "tau_gen_match_2__tauEs1prong0pizeroDown", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__tauEs1prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df29 = scalefactor::tau::id_vsMu(df28, correctionManager, "eta_2__tauEs1prong1pizeroDown", "tau_decaymode_2__tauEs1prong1pizeroDown", "tau_gen_match_2__tauEs1prong1pizeroDown", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__tauEs1prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df30 = scalefactor::tau::id_vsMu(df29, correctionManager, "eta_2__tauEs1prong1pizeroDown", "tau_decaymode_2__tauEs1prong1pizeroDown", "tau_gen_match_2__tauEs1prong1pizeroDown", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__tauEs1prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df31 = scalefactor::tau::id_vsMu(df30, correctionManager, "eta_2__tauEs1prong1pizeroDown", "tau_decaymode_2__tauEs1prong1pizeroDown", "tau_gen_match_2__tauEs1prong1pizeroDown", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__tauEs1prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df32 = scalefactor::tau::id_vsMu(df31, correctionManager, "eta_2__tauEs1prong1pizeroDown", "tau_decaymode_2__tauEs1prong1pizeroDown", "tau_gen_match_2__tauEs1prong1pizeroDown", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__tauEs1prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df33 = scalefactor::tau::id_vsMu(df32, correctionManager, "eta_2__tauEs3prong1pizeroUp", "tau_decaymode_2__tauEs3prong1pizeroUp", "tau_gen_match_2__tauEs3prong1pizeroUp", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__tauEs3prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df34 = scalefactor::tau::id_vsMu(df33, correctionManager, "eta_2__tauEs3prong1pizeroUp", "tau_decaymode_2__tauEs3prong1pizeroUp", "tau_gen_match_2__tauEs3prong1pizeroUp", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__tauEs3prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df35 = scalefactor::tau::id_vsMu(df34, correctionManager, "eta_2__tauEs3prong1pizeroUp", "tau_decaymode_2__tauEs3prong1pizeroUp", "tau_gen_match_2__tauEs3prong1pizeroUp", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__tauEs3prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df36 = scalefactor::tau::id_vsMu(df35, correctionManager, "eta_2__tauEs3prong1pizeroUp", "tau_decaymode_2__tauEs3prong1pizeroUp", "tau_gen_match_2__tauEs3prong1pizeroUp", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__tauEs3prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df37 = scalefactor::tau::id_vsMu(df36, correctionManager, "eta_2__tauEs1prong1pizeroUp", "tau_decaymode_2__tauEs1prong1pizeroUp", "tau_gen_match_2__tauEs1prong1pizeroUp", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__tauEs1prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df38 = scalefactor::tau::id_vsMu(df37, correctionManager, "eta_2__tauEs1prong1pizeroUp", "tau_decaymode_2__tauEs1prong1pizeroUp", "tau_gen_match_2__tauEs1prong1pizeroUp", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__tauEs1prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df39 = scalefactor::tau::id_vsMu(df38, correctionManager, "eta_2__tauEs1prong1pizeroUp", "tau_decaymode_2__tauEs1prong1pizeroUp", "tau_gen_match_2__tauEs1prong1pizeroUp", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__tauEs1prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df40 = scalefactor::tau::id_vsMu(df39, correctionManager, "eta_2__tauEs1prong1pizeroUp", "tau_decaymode_2__tauEs1prong1pizeroUp", "tau_gen_match_2__tauEs1prong1pizeroUp", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__tauEs1prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df41 = scalefactor::tau::id_vsMu(df40, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "down", "nom", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel4Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df42 = scalefactor::tau::id_vsMu(df41, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "nom", "down", "nom", "id_wgt_tau_vsMu_Loose_2__vsMuWheel4Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df43 = scalefactor::tau::id_vsMu(df42, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "nom", "down", "nom", "id_wgt_tau_vsMu_Medium_2__vsMuWheel4Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df44 = scalefactor::tau::id_vsMu(df43, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "nom", "down", "nom", "id_wgt_tau_vsMu_Tight_2__vsMuWheel4Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df45 = scalefactor::tau::id_vsMu(df44, correctionManager, "eta_2__tauEs1prong0pizeroUp", "tau_decaymode_2__tauEs1prong0pizeroUp", "tau_gen_match_2__tauEs1prong0pizeroUp", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__tauEs1prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df46 = scalefactor::tau::id_vsMu(df45, correctionManager, "eta_2__tauEs1prong0pizeroUp", "tau_decaymode_2__tauEs1prong0pizeroUp", "tau_gen_match_2__tauEs1prong0pizeroUp", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__tauEs1prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df47 = scalefactor::tau::id_vsMu(df46, correctionManager, "eta_2__tauEs1prong0pizeroUp", "tau_decaymode_2__tauEs1prong0pizeroUp", "tau_gen_match_2__tauEs1prong0pizeroUp", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__tauEs1prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df48 = scalefactor::tau::id_vsMu(df47, correctionManager, "eta_2__tauEs1prong0pizeroUp", "tau_decaymode_2__tauEs1prong0pizeroUp", "tau_gen_match_2__tauEs1prong0pizeroUp", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__tauEs1prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df49 = scalefactor::tau::id_vsMu(df48, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "nom", "down", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel3Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df50 = scalefactor::tau::id_vsMu(df49, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "down", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__vsMuWheel3Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df51 = scalefactor::tau::id_vsMu(df50, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "down", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__vsMuWheel3Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df52 = scalefactor::tau::id_vsMu(df51, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "down", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__vsMuWheel3Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df53 = scalefactor::tau::id_vsMu(df52, correctionManager, "eta_2__tauEs3prong0pizeroDown", "tau_decaymode_2__tauEs3prong0pizeroDown", "tau_gen_match_2__tauEs3prong0pizeroDown", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__tauEs3prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df54 = scalefactor::tau::id_vsMu(df53, correctionManager, "eta_2__tauEs3prong0pizeroDown", "tau_decaymode_2__tauEs3prong0pizeroDown", "tau_gen_match_2__tauEs3prong0pizeroDown", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__tauEs3prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df55 = scalefactor::tau::id_vsMu(df54, correctionManager, "eta_2__tauEs3prong0pizeroDown", "tau_decaymode_2__tauEs3prong0pizeroDown", "tau_gen_match_2__tauEs3prong0pizeroDown", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__tauEs3prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df56 = scalefactor::tau::id_vsMu(df55, correctionManager, "eta_2__tauEs3prong0pizeroDown", "tau_decaymode_2__tauEs3prong0pizeroDown", "tau_gen_match_2__tauEs3prong0pizeroDown", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__tauEs3prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df57 = scalefactor::tau::id_vsMu(df56, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "up", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel2Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df58 = scalefactor::tau::id_vsMu(df57, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "up", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__vsMuWheel2Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df59 = scalefactor::tau::id_vsMu(df58, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "up", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__vsMuWheel2Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df60 = scalefactor::tau::id_vsMu(df59, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "up", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__vsMuWheel2Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df61 = scalefactor::tau::id_vsMu(df60, correctionManager, "eta_2__tauEs3prong0pizeroUp", "tau_decaymode_2__tauEs3prong0pizeroUp", "tau_gen_match_2__tauEs3prong0pizeroUp", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__tauEs3prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df62 = scalefactor::tau::id_vsMu(df61, correctionManager, "eta_2__tauEs3prong0pizeroUp", "tau_decaymode_2__tauEs3prong0pizeroUp", "tau_gen_match_2__tauEs3prong0pizeroUp", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__tauEs3prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df63 = scalefactor::tau::id_vsMu(df62, correctionManager, "eta_2__tauEs3prong0pizeroUp", "tau_decaymode_2__tauEs3prong0pizeroUp", "tau_gen_match_2__tauEs3prong0pizeroUp", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__tauEs3prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df64 = scalefactor::tau::id_vsMu(df63, correctionManager, "eta_2__tauEs3prong0pizeroUp", "tau_decaymode_2__tauEs3prong0pizeroUp", "tau_gen_match_2__tauEs3prong0pizeroUp", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__tauEs3prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df65 = scalefactor::tau::id_vsMu(df64, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "nom", "up", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel3Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df66 = scalefactor::tau::id_vsMu(df65, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "up", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__vsMuWheel3Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df67 = scalefactor::tau::id_vsMu(df66, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "up", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__vsMuWheel3Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df68 = scalefactor::tau::id_vsMu(df67, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "up", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__vsMuWheel3Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df69 = scalefactor::tau::id_vsMu(df68, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "nom", "nom", "nom", "nom", "up", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel5Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df70 = scalefactor::tau::id_vsMu(df69, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "up", "id_wgt_tau_vsMu_Loose_2__vsMuWheel5Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df71 = scalefactor::tau::id_vsMu(df70, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "up", "id_wgt_tau_vsMu_Medium_2__vsMuWheel5Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df72 = scalefactor::tau::id_vsMu(df71, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "up", "id_wgt_tau_vsMu_Tight_2__vsMuWheel5Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df73 = scalefactor::tau::id_vsMu(df72, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VLoose", "up", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_VLoose_2__vsMuWheel1Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df74 = scalefactor::tau::id_vsMu(df73, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "up", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Loose_2__vsMuWheel1Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df75 = scalefactor::tau::id_vsMu(df74, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "up", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Medium_2__vsMuWheel1Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    auto df76 = scalefactor::tau::id_vsMu(df75, correctionManager, "eta_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "up", "nom", "nom", "nom", "nom", "id_wgt_tau_vsMu_Tight_2__vsMuWheel1Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSmu");
    return df76;

}
