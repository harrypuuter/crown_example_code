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
ROOT::RDF::RNode Tau_2_VsJetTauID_tt_SF_tt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = scalefactor::tau::id_vsJet_tt(df0, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df2 = scalefactor::tau::id_vsJet_tt(df1, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df3 = scalefactor::tau::id_vsJet_tt(df2, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df4 = scalefactor::tau::id_vsJet_tt(df3, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df5 = scalefactor::tau::id_vsJet_tt(df4, correctionManager, "pt_2__tauEs3prong1pizeroDown", "tau_decaymode_2__tauEs3prong1pizeroDown", "tau_gen_match_2__tauEs3prong1pizeroDown", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__tauEs3prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df6 = scalefactor::tau::id_vsJet_tt(df5, correctionManager, "pt_2__tauEs3prong1pizeroDown", "tau_decaymode_2__tauEs3prong1pizeroDown", "tau_gen_match_2__tauEs3prong1pizeroDown", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__tauEs3prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df7 = scalefactor::tau::id_vsJet_tt(df6, correctionManager, "pt_2__tauEs3prong1pizeroDown", "tau_decaymode_2__tauEs3prong1pizeroDown", "tau_gen_match_2__tauEs3prong1pizeroDown", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__tauEs3prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df8 = scalefactor::tau::id_vsJet_tt(df7, correctionManager, "pt_2__tauEs3prong1pizeroDown", "tau_decaymode_2__tauEs3prong1pizeroDown", "tau_gen_match_2__tauEs3prong1pizeroDown", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__tauEs3prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df9 = scalefactor::tau::id_vsJet_tt(df8, correctionManager, "pt_2__tauEs3prong0pizeroDown", "tau_decaymode_2__tauEs3prong0pizeroDown", "tau_gen_match_2__tauEs3prong0pizeroDown", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__tauEs3prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df10 = scalefactor::tau::id_vsJet_tt(df9, correctionManager, "pt_2__tauEs3prong0pizeroDown", "tau_decaymode_2__tauEs3prong0pizeroDown", "tau_gen_match_2__tauEs3prong0pizeroDown", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__tauEs3prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df11 = scalefactor::tau::id_vsJet_tt(df10, correctionManager, "pt_2__tauEs3prong0pizeroDown", "tau_decaymode_2__tauEs3prong0pizeroDown", "tau_gen_match_2__tauEs3prong0pizeroDown", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__tauEs3prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df12 = scalefactor::tau::id_vsJet_tt(df11, correctionManager, "pt_2__tauEs3prong0pizeroDown", "tau_decaymode_2__tauEs3prong0pizeroDown", "tau_gen_match_2__tauEs3prong0pizeroDown", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__tauEs3prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df13 = scalefactor::tau::id_vsJet_tt(df12, correctionManager, "pt_2__tauEs1prong0pizeroDown", "tau_decaymode_2__tauEs1prong0pizeroDown", "tau_gen_match_2__tauEs1prong0pizeroDown", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__tauEs1prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df14 = scalefactor::tau::id_vsJet_tt(df13, correctionManager, "pt_2__tauEs1prong0pizeroDown", "tau_decaymode_2__tauEs1prong0pizeroDown", "tau_gen_match_2__tauEs1prong0pizeroDown", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__tauEs1prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df15 = scalefactor::tau::id_vsJet_tt(df14, correctionManager, "pt_2__tauEs1prong0pizeroDown", "tau_decaymode_2__tauEs1prong0pizeroDown", "tau_gen_match_2__tauEs1prong0pizeroDown", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__tauEs1prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df16 = scalefactor::tau::id_vsJet_tt(df15, correctionManager, "pt_2__tauEs1prong0pizeroDown", "tau_decaymode_2__tauEs1prong0pizeroDown", "tau_gen_match_2__tauEs1prong0pizeroDown", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__tauEs1prong0pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df17 = scalefactor::tau::id_vsJet_tt(df16, correctionManager, "pt_2__tauEs3prong1pizeroUp", "tau_decaymode_2__tauEs3prong1pizeroUp", "tau_gen_match_2__tauEs3prong1pizeroUp", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__tauEs3prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df18 = scalefactor::tau::id_vsJet_tt(df17, correctionManager, "pt_2__tauEs3prong1pizeroUp", "tau_decaymode_2__tauEs3prong1pizeroUp", "tau_gen_match_2__tauEs3prong1pizeroUp", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__tauEs3prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df19 = scalefactor::tau::id_vsJet_tt(df18, correctionManager, "pt_2__tauEs3prong1pizeroUp", "tau_decaymode_2__tauEs3prong1pizeroUp", "tau_gen_match_2__tauEs3prong1pizeroUp", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__tauEs3prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df20 = scalefactor::tau::id_vsJet_tt(df19, correctionManager, "pt_2__tauEs3prong1pizeroUp", "tau_decaymode_2__tauEs3prong1pizeroUp", "tau_gen_match_2__tauEs3prong1pizeroUp", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__tauEs3prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df21 = scalefactor::tau::id_vsJet_tt(df20, correctionManager, "pt_2__tauEs1prong1pizeroDown", "tau_decaymode_2__tauEs1prong1pizeroDown", "tau_gen_match_2__tauEs1prong1pizeroDown", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__tauEs1prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df22 = scalefactor::tau::id_vsJet_tt(df21, correctionManager, "pt_2__tauEs1prong1pizeroDown", "tau_decaymode_2__tauEs1prong1pizeroDown", "tau_gen_match_2__tauEs1prong1pizeroDown", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__tauEs1prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df23 = scalefactor::tau::id_vsJet_tt(df22, correctionManager, "pt_2__tauEs1prong1pizeroDown", "tau_decaymode_2__tauEs1prong1pizeroDown", "tau_gen_match_2__tauEs1prong1pizeroDown", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__tauEs1prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df24 = scalefactor::tau::id_vsJet_tt(df23, correctionManager, "pt_2__tauEs1prong1pizeroDown", "tau_decaymode_2__tauEs1prong1pizeroDown", "tau_gen_match_2__tauEs1prong1pizeroDown", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__tauEs1prong1pizeroDown", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df25 = scalefactor::tau::id_vsJet_tt(df24, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "up", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__vsJetTauDM1Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df26 = scalefactor::tau::id_vsJet_tt(df25, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "up", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__vsJetTauDM1Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df27 = scalefactor::tau::id_vsJet_tt(df26, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "up", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__vsJetTauDM1Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df28 = scalefactor::tau::id_vsJet_tt(df27, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "nom", "up", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__vsJetTauDM1Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df29 = scalefactor::tau::id_vsJet_tt(df28, correctionManager, "pt_2__tauEs1prong1pizeroUp", "tau_decaymode_2__tauEs1prong1pizeroUp", "tau_gen_match_2__tauEs1prong1pizeroUp", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__tauEs1prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df30 = scalefactor::tau::id_vsJet_tt(df29, correctionManager, "pt_2__tauEs1prong1pizeroUp", "tau_decaymode_2__tauEs1prong1pizeroUp", "tau_gen_match_2__tauEs1prong1pizeroUp", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__tauEs1prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df31 = scalefactor::tau::id_vsJet_tt(df30, correctionManager, "pt_2__tauEs1prong1pizeroUp", "tau_decaymode_2__tauEs1prong1pizeroUp", "tau_gen_match_2__tauEs1prong1pizeroUp", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__tauEs1prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df32 = scalefactor::tau::id_vsJet_tt(df31, correctionManager, "pt_2__tauEs1prong1pizeroUp", "tau_decaymode_2__tauEs1prong1pizeroUp", "tau_gen_match_2__tauEs1prong1pizeroUp", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__tauEs1prong1pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df33 = scalefactor::tau::id_vsJet_tt(df32, correctionManager, "pt_2__tauEs1prong0pizeroUp", "tau_decaymode_2__tauEs1prong0pizeroUp", "tau_gen_match_2__tauEs1prong0pizeroUp", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__tauEs1prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df34 = scalefactor::tau::id_vsJet_tt(df33, correctionManager, "pt_2__tauEs1prong0pizeroUp", "tau_decaymode_2__tauEs1prong0pizeroUp", "tau_gen_match_2__tauEs1prong0pizeroUp", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__tauEs1prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df35 = scalefactor::tau::id_vsJet_tt(df34, correctionManager, "pt_2__tauEs1prong0pizeroUp", "tau_decaymode_2__tauEs1prong0pizeroUp", "tau_gen_match_2__tauEs1prong0pizeroUp", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__tauEs1prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df36 = scalefactor::tau::id_vsJet_tt(df35, correctionManager, "pt_2__tauEs1prong0pizeroUp", "tau_decaymode_2__tauEs1prong0pizeroUp", "tau_gen_match_2__tauEs1prong0pizeroUp", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__tauEs1prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df37 = scalefactor::tau::id_vsJet_tt(df36, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "down", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__vsJetTauDM0Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df38 = scalefactor::tau::id_vsJet_tt(df37, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "down", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__vsJetTauDM0Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df39 = scalefactor::tau::id_vsJet_tt(df38, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "down", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__vsJetTauDM0Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df40 = scalefactor::tau::id_vsJet_tt(df39, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "down", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__vsJetTauDM0Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df41 = scalefactor::tau::id_vsJet_tt(df40, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "down", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__vsJetTauDM10Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df42 = scalefactor::tau::id_vsJet_tt(df41, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "down", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__vsJetTauDM10Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df43 = scalefactor::tau::id_vsJet_tt(df42, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "down", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__vsJetTauDM10Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df44 = scalefactor::tau::id_vsJet_tt(df43, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "nom", "nom", "down", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__vsJetTauDM10Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df45 = scalefactor::tau::id_vsJet_tt(df44, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "down", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__vsJetTauDM1Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df46 = scalefactor::tau::id_vsJet_tt(df45, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "down", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__vsJetTauDM1Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df47 = scalefactor::tau::id_vsJet_tt(df46, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "down", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__vsJetTauDM1Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df48 = scalefactor::tau::id_vsJet_tt(df47, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "nom", "down", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__vsJetTauDM1Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df49 = scalefactor::tau::id_vsJet_tt(df48, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "up", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__vsJetTauDM10Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df50 = scalefactor::tau::id_vsJet_tt(df49, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "up", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__vsJetTauDM10Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df51 = scalefactor::tau::id_vsJet_tt(df50, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "up", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__vsJetTauDM10Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df52 = scalefactor::tau::id_vsJet_tt(df51, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "nom", "nom", "up", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__vsJetTauDM10Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df53 = scalefactor::tau::id_vsJet_tt(df52, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "nom", "up", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__vsJetTauDM11Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df54 = scalefactor::tau::id_vsJet_tt(df53, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "nom", "up", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__vsJetTauDM11Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df55 = scalefactor::tau::id_vsJet_tt(df54, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "nom", "up", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__vsJetTauDM11Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df56 = scalefactor::tau::id_vsJet_tt(df55, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "nom", "nom", "nom", "up", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__vsJetTauDM11Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df57 = scalefactor::tau::id_vsJet_tt(df56, correctionManager, "pt_2__tauEs3prong0pizeroUp", "tau_decaymode_2__tauEs3prong0pizeroUp", "tau_gen_match_2__tauEs3prong0pizeroUp", {0,1,10,11}, "Loose", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__tauEs3prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df58 = scalefactor::tau::id_vsJet_tt(df57, correctionManager, "pt_2__tauEs3prong0pizeroUp", "tau_decaymode_2__tauEs3prong0pizeroUp", "tau_gen_match_2__tauEs3prong0pizeroUp", {0,1,10,11}, "Medium", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__tauEs3prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df59 = scalefactor::tau::id_vsJet_tt(df58, correctionManager, "pt_2__tauEs3prong0pizeroUp", "tau_decaymode_2__tauEs3prong0pizeroUp", "tau_gen_match_2__tauEs3prong0pizeroUp", {0,1,10,11}, "Tight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__tauEs3prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df60 = scalefactor::tau::id_vsJet_tt(df59, correctionManager, "pt_2__tauEs3prong0pizeroUp", "tau_decaymode_2__tauEs3prong0pizeroUp", "tau_gen_match_2__tauEs3prong0pizeroUp", {0,1,10,11}, "VTight", "nom", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__tauEs3prong0pizeroUp", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df61 = scalefactor::tau::id_vsJet_tt(df60, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "nom", "nom", "nom", "down", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__vsJetTauDM11Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df62 = scalefactor::tau::id_vsJet_tt(df61, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "nom", "nom", "nom", "down", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__vsJetTauDM11Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df63 = scalefactor::tau::id_vsJet_tt(df62, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "nom", "nom", "nom", "down", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__vsJetTauDM11Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df64 = scalefactor::tau::id_vsJet_tt(df63, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "nom", "nom", "nom", "down", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__vsJetTauDM11Down", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df65 = scalefactor::tau::id_vsJet_tt(df64, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Loose", "up", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Loose_2__vsJetTauDM0Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df66 = scalefactor::tau::id_vsJet_tt(df65, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Medium", "up", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Medium_2__vsJetTauDM0Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df67 = scalefactor::tau::id_vsJet_tt(df66, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "Tight", "up", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_Tight_2__vsJetTauDM0Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    auto df68 = scalefactor::tau::id_vsJet_tt(df67, correctionManager, "pt_2", "tau_decaymode_2", "tau_gen_match_2", {0,1,10,11}, "VTight", "up", "nom", "nom", "nom", "dm", "VVLoose", "id_wgt_tau_vsJet_VTight_2__vsJetTauDM0Up", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "DeepTau2017v2p1VSjet");
    return df68;

}
