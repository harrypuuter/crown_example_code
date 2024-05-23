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
ROOT::RDF::RNode PFMetCorrections_mt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = met::propagateLeptonsToMet(df0, "pfmet_p4", "p4_1_uncorrected", "p4_2_uncorrected", "p4_1", "p4_2", "pfmet_p4_leptoncorrected", true);
    auto df2 = met::propagateLeptonsToMet(df1, "pfmet_p4", "p4_1_uncorrected__tauEs3prong1pizeroDown", "p4_2_uncorrected__tauEs3prong1pizeroDown", "p4_1", "p4_2__tauEs3prong1pizeroDown", "pfmet_p4_leptoncorrected__tauEs3prong1pizeroDown", true);
    auto df3 = met::propagateLeptonsToMet(df2, "pfmet_p4", "p4_1_uncorrected__tauEs1prong0pizeroDown", "p4_2_uncorrected__tauEs1prong0pizeroDown", "p4_1", "p4_2__tauEs1prong0pizeroDown", "pfmet_p4_leptoncorrected__tauEs1prong0pizeroDown", true);
    auto df4 = met::propagateLeptonsToMet(df3, "pfmet_p4", "p4_1_uncorrected__tauEs3prong1pizeroUp", "p4_2_uncorrected__tauEs3prong1pizeroUp", "p4_1", "p4_2__tauEs3prong1pizeroUp", "pfmet_p4_leptoncorrected__tauEs3prong1pizeroUp", true);
    auto df5 = met::propagateLeptonsToMet(df4, "pfmet_p4", "p4_1_uncorrected__tauEs1prong1pizeroDown", "p4_2_uncorrected__tauEs1prong1pizeroDown", "p4_1", "p4_2__tauEs1prong1pizeroDown", "pfmet_p4_leptoncorrected__tauEs1prong1pizeroDown", true);
    auto df6 = met::propagateLeptonsToMet(df5, "pfmet_p4", "p4_1_uncorrected__tauEs1prong1pizeroUp", "p4_2_uncorrected__tauEs1prong1pizeroUp", "p4_1", "p4_2__tauEs1prong1pizeroUp", "pfmet_p4_leptoncorrected__tauEs1prong1pizeroUp", true);
    auto df7 = met::propagateLeptonsToMet(df6, "pfmet_p4", "p4_1_uncorrected__tauEs1prong0pizeroUp", "p4_2_uncorrected__tauEs1prong0pizeroUp", "p4_1", "p4_2__tauEs1prong0pizeroUp", "pfmet_p4_leptoncorrected__tauEs1prong0pizeroUp", true);
    auto df8 = met::propagateLeptonsToMet(df7, "pfmet_p4", "p4_1_uncorrected__tauEs3prong0pizeroDown", "p4_2_uncorrected__tauEs3prong0pizeroDown", "p4_1", "p4_2__tauEs3prong0pizeroDown", "pfmet_p4_leptoncorrected__tauEs3prong0pizeroDown", true);
    auto df9 = met::propagateLeptonsToMet(df8, "pfmet_p4", "p4_1_uncorrected__tauEs3prong0pizeroUp", "p4_2_uncorrected__tauEs3prong0pizeroUp", "p4_1", "p4_2__tauEs3prong0pizeroUp", "pfmet_p4_leptoncorrected__tauEs3prong0pizeroUp", true);
    auto df10 = met::propagateJetsToMet(df9, "pfmet_p4_leptoncorrected", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected", true, 15);
    auto df11 = met::propagateJetsToMet(df10, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncFlavorQCDUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncFlavorQCDUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncFlavorQCDUp", true, 15);
    auto df12 = met::propagateJetsToMet(df11, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncHFDown", true, 15);
    auto df13 = met::propagateJetsToMet(df12, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeBalUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeBalUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncRelativeBalUp", true, 15);
    auto df14 = met::propagateJetsToMet(df13, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncTotalDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncTotalDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncTotalDown", true, 15);
    auto df15 = met::propagateJetsToMet(df14, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeSampleYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeSampleYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncRelativeSampleYearUp", true, 15);
    auto df16 = met::propagateJetsToMet(df15, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncAbsoluteDown", true, 15);
    auto df17 = met::propagateJetsToMet(df16, "pfmet_p4_leptoncorrected__tauEs1prong1pizeroUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__tauEs1prong1pizeroUp", true, 15);
    auto df18 = met::propagateJetsToMet(df17, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jerUncUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jerUncUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jerUncUp", true, 15);
    auto df19 = met::propagateJetsToMet(df18, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jerUncDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jerUncDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jerUncDown", true, 15);
    auto df20 = met::propagateJetsToMet(df19, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2YearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2YearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncEC2YearDown", true, 15);
    auto df21 = met::propagateJetsToMet(df20, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1Down", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1Down", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncBBEC1Down", true, 15);
    auto df22 = met::propagateJetsToMet(df21, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2Down", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2Down", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncEC2Down", true, 15);
    auto df23 = met::propagateJetsToMet(df22, "pfmet_p4_leptoncorrected__tauEs3prong1pizeroDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__tauEs3prong1pizeroDown", true, 15);
    auto df24 = met::propagateJetsToMet(df23, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncAbsoluteYearDown", true, 15);
    auto df25 = met::propagateJetsToMet(df24, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeBalDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeBalDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncRelativeBalDown", true, 15);
    auto df26 = met::propagateJetsToMet(df25, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncTotalUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncTotalUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncTotalUp", true, 15);
    auto df27 = met::propagateJetsToMet(df26, "pfmet_p4_leptoncorrected__tauEs1prong0pizeroUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__tauEs1prong0pizeroUp", true, 15);
    auto df28 = met::propagateJetsToMet(df27, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1YearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1YearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncBBEC1YearUp", true, 15);
    auto df29 = met::propagateJetsToMet(df28, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncHEMIssueUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHEMIssueUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncHEMIssueUp", true, 15);
    auto df30 = met::propagateJetsToMet(df29, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeSampleYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeSampleYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncRelativeSampleYearDown", true, 15);
    auto df31 = met::propagateJetsToMet(df30, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncHFUp", true, 15);
    auto df32 = met::propagateJetsToMet(df31, "pfmet_p4_leptoncorrected__tauEs1prong0pizeroDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__tauEs1prong0pizeroDown", true, 15);
    auto df33 = met::propagateJetsToMet(df32, "pfmet_p4_leptoncorrected__tauEs1prong1pizeroDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__tauEs1prong1pizeroDown", true, 15);
    auto df34 = met::propagateJetsToMet(df33, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncFlavorQCDDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncFlavorQCDDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncFlavorQCDDown", true, 15);
    auto df35 = met::propagateJetsToMet(df34, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncHEMIssueDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHEMIssueDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncHEMIssueDown", true, 15);
    auto df36 = met::propagateJetsToMet(df35, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncAbsoluteUp", true, 15);
    auto df37 = met::propagateJetsToMet(df36, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2YearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2YearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncEC2YearUp", true, 15);
    auto df38 = met::propagateJetsToMet(df37, "pfmet_p4_leptoncorrected__tauEs3prong0pizeroUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__tauEs3prong0pizeroUp", true, 15);
    auto df39 = met::propagateJetsToMet(df38, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1Up", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1Up", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncBBEC1Up", true, 15);
    auto df40 = met::propagateJetsToMet(df39, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2Up", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2Up", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncEC2Up", true, 15);
    auto df41 = met::propagateJetsToMet(df40, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncAbsoluteYearUp", true, 15);
    auto df42 = met::propagateJetsToMet(df41, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncHFYearUp", true, 15);
    auto df43 = met::propagateJetsToMet(df42, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncHFYearDown", true, 15);
    auto df44 = met::propagateJetsToMet(df43, "pfmet_p4_leptoncorrected__tauEs3prong1pizeroUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__tauEs3prong1pizeroUp", true, 15);
    auto df45 = met::propagateJetsToMet(df44, "pfmet_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1YearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1YearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__jesUncBBEC1YearDown", true, 15);
    auto df46 = met::propagateJetsToMet(df45, "pfmet_p4_leptoncorrected__tauEs3prong0pizeroDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "pfmet_p4_jetcorrected__tauEs3prong0pizeroDown", true, 15);
    auto df47 = met::applyRecoilCorrections(df46, "pfmet_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df48 = met::applyRecoilCorrections(df47, "pfmet_p4_jetcorrected__jesUncFlavorQCDUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncFlavorQCDUp", "pfmet_p4_recoilcorrected__jesUncFlavorQCDUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df49 = met::applyRecoilCorrections(df48, "pfmet_p4_jetcorrected__jesUncHFDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFDown", "pfmet_p4_recoilcorrected__jesUncHFDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df50 = met::applyRecoilCorrections(df49, "pfmet_p4_jetcorrected__jesUncRelativeBalUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeBalUp", "pfmet_p4_recoilcorrected__jesUncRelativeBalUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df51 = met::applyRecoilCorrections(df50, "pfmet_p4_jetcorrected__jesUncTotalDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncTotalDown", "pfmet_p4_recoilcorrected__jesUncTotalDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df52 = met::applyRecoilCorrections(df51, "pfmet_p4_jetcorrected__jesUncRelativeSampleYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeSampleYearUp", "pfmet_p4_recoilcorrected__jesUncRelativeSampleYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df53 = met::applyRecoilCorrections(df52, "pfmet_p4_jetcorrected__jesUncAbsoluteDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteDown", "pfmet_p4_recoilcorrected__jesUncAbsoluteDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df54 = met::applyRecoilCorrections(df53, "pfmet_p4_jetcorrected__tauEs1prong1pizeroUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected__tauEs1prong1pizeroUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df55 = met::applyRecoilCorrections(df54, "pfmet_p4_jetcorrected__jerUncUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jerUncUp", "pfmet_p4_recoilcorrected__jerUncUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df56 = met::applyRecoilCorrections(df55, "pfmet_p4_jetcorrected__jerUncDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jerUncDown", "pfmet_p4_recoilcorrected__jerUncDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df57 = met::applyRecoilCorrections(df56, "pfmet_p4_jetcorrected__jesUncEC2YearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2YearDown", "pfmet_p4_recoilcorrected__jesUncEC2YearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df58 = met::applyRecoilCorrections(df57, "pfmet_p4_jetcorrected__jesUncBBEC1Down", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1Down", "pfmet_p4_recoilcorrected__jesUncBBEC1Down", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df59 = met::applyRecoilCorrections(df58, "pfmet_p4_jetcorrected__jesUncEC2Down", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2Down", "pfmet_p4_recoilcorrected__jesUncEC2Down", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df60 = met::applyRecoilCorrections(df59, "pfmet_p4_jetcorrected__tauEs3prong1pizeroDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected__tauEs3prong1pizeroDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df61 = met::applyRecoilCorrections(df60, "pfmet_p4_jetcorrected__jesUncAbsoluteYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteYearDown", "pfmet_p4_recoilcorrected__jesUncAbsoluteYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df62 = met::applyRecoilCorrections(df61, "pfmet_p4_jetcorrected__jesUncRelativeBalDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeBalDown", "pfmet_p4_recoilcorrected__jesUncRelativeBalDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df63 = met::applyRecoilCorrections(df62, "pfmet_p4_jetcorrected__jesUncTotalUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncTotalUp", "pfmet_p4_recoilcorrected__jesUncTotalUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df64 = met::applyRecoilCorrections(df63, "pfmet_p4_jetcorrected__tauEs1prong0pizeroUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected__tauEs1prong0pizeroUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df65 = met::applyRecoilCorrections(df64, "pfmet_p4_jetcorrected__jesUncBBEC1YearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1YearUp", "pfmet_p4_recoilcorrected__jesUncBBEC1YearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df66 = met::applyRecoilCorrections(df65, "pfmet_p4_jetcorrected__jesUncHEMIssueUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHEMIssueUp", "pfmet_p4_recoilcorrected__jesUncHEMIssueUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df67 = met::applyRecoilCorrections(df66, "pfmet_p4_jetcorrected__jesUncRelativeSampleYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeSampleYearDown", "pfmet_p4_recoilcorrected__jesUncRelativeSampleYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df68 = met::applyRecoilCorrections(df67, "pfmet_p4_jetcorrected__jesUncHFUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFUp", "pfmet_p4_recoilcorrected__jesUncHFUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df69 = met::applyRecoilCorrections(df68, "pfmet_p4_jetcorrected__tauEs1prong0pizeroDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected__tauEs1prong0pizeroDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df70 = met::applyRecoilCorrections(df69, "pfmet_p4_jetcorrected__tauEs1prong1pizeroDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected__tauEs1prong1pizeroDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df71 = met::applyRecoilCorrections(df70, "pfmet_p4_jetcorrected__jesUncFlavorQCDDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncFlavorQCDDown", "pfmet_p4_recoilcorrected__jesUncFlavorQCDDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df72 = met::applyRecoilCorrections(df71, "pfmet_p4_jetcorrected__jesUncHEMIssueDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHEMIssueDown", "pfmet_p4_recoilcorrected__jesUncHEMIssueDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df73 = met::applyRecoilCorrections(df72, "pfmet_p4_jetcorrected__jesUncAbsoluteUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteUp", "pfmet_p4_recoilcorrected__jesUncAbsoluteUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df74 = met::applyRecoilCorrections(df73, "pfmet_p4_jetcorrected__jesUncEC2YearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2YearUp", "pfmet_p4_recoilcorrected__jesUncEC2YearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df75 = met::applyRecoilCorrections(df74, "pfmet_p4_jetcorrected__tauEs3prong0pizeroUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected__tauEs3prong0pizeroUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df76 = met::applyRecoilCorrections(df75, "pfmet_p4_jetcorrected__jesUncBBEC1Up", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1Up", "pfmet_p4_recoilcorrected__jesUncBBEC1Up", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df77 = met::applyRecoilCorrections(df76, "pfmet_p4_jetcorrected__jesUncEC2Up", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2Up", "pfmet_p4_recoilcorrected__jesUncEC2Up", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df78 = met::applyRecoilCorrections(df77, "pfmet_p4_jetcorrected__jesUncAbsoluteYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteYearUp", "pfmet_p4_recoilcorrected__jesUncAbsoluteYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df79 = met::applyRecoilCorrections(df78, "pfmet_p4_jetcorrected__jesUncHFYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFYearUp", "pfmet_p4_recoilcorrected__jesUncHFYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df80 = met::applyRecoilCorrections(df79, "pfmet_p4_jetcorrected__jesUncHFYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFYearDown", "pfmet_p4_recoilcorrected__jesUncHFYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df81 = met::applyRecoilCorrections(df80, "pfmet_p4_jetcorrected__tauEs3prong1pizeroUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected__tauEs3prong1pizeroUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df82 = met::applyRecoilCorrections(df81, "pfmet_p4_jetcorrected__jesUncBBEC1YearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1YearDown", "pfmet_p4_recoilcorrected__jesUncBBEC1YearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df83 = met::applyRecoilCorrections(df82, "pfmet_p4_jetcorrected__tauEs3prong0pizeroDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "pfmet_p4_recoilcorrected__tauEs3prong0pizeroDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df84 = quantities::pt(df83, "pfmet", "pfmet_p4_recoilcorrected");
    auto df85 = quantities::pt(df84, "pfmet__jesUncFlavorQCDUp", "pfmet_p4_recoilcorrected__jesUncFlavorQCDUp");
    auto df86 = quantities::pt(df85, "pfmet__jesUncHFDown", "pfmet_p4_recoilcorrected__jesUncHFDown");
    auto df87 = quantities::pt(df86, "pfmet__jesUncRelativeBalUp", "pfmet_p4_recoilcorrected__jesUncRelativeBalUp");
    auto df88 = quantities::pt(df87, "pfmet__jesUncTotalDown", "pfmet_p4_recoilcorrected__jesUncTotalDown");
    auto df89 = quantities::pt(df88, "pfmet__jesUncRelativeSampleYearUp", "pfmet_p4_recoilcorrected__jesUncRelativeSampleYearUp");
    auto df90 = quantities::pt(df89, "pfmet__jesUncAbsoluteDown", "pfmet_p4_recoilcorrected__jesUncAbsoluteDown");
    auto df91 = quantities::pt(df90, "pfmet__tauEs1prong1pizeroUp", "pfmet_p4_recoilcorrected__tauEs1prong1pizeroUp");
    auto df92 = quantities::pt(df91, "pfmet__jerUncUp", "pfmet_p4_recoilcorrected__jerUncUp");
    auto df93 = quantities::pt(df92, "pfmet__jerUncDown", "pfmet_p4_recoilcorrected__jerUncDown");
    auto df94 = quantities::pt(df93, "pfmet__jesUncEC2YearDown", "pfmet_p4_recoilcorrected__jesUncEC2YearDown");
    auto df95 = quantities::pt(df94, "pfmet__jesUncBBEC1Down", "pfmet_p4_recoilcorrected__jesUncBBEC1Down");
    auto df96 = quantities::pt(df95, "pfmet__jesUncEC2Down", "pfmet_p4_recoilcorrected__jesUncEC2Down");
    auto df97 = quantities::pt(df96, "pfmet__tauEs3prong1pizeroDown", "pfmet_p4_recoilcorrected__tauEs3prong1pizeroDown");
    auto df98 = quantities::pt(df97, "pfmet__jesUncAbsoluteYearDown", "pfmet_p4_recoilcorrected__jesUncAbsoluteYearDown");
    auto df99 = quantities::pt(df98, "pfmet__jesUncRelativeBalDown", "pfmet_p4_recoilcorrected__jesUncRelativeBalDown");
    auto df100 = quantities::pt(df99, "pfmet__jesUncTotalUp", "pfmet_p4_recoilcorrected__jesUncTotalUp");
    auto df101 = quantities::pt(df100, "pfmet__tauEs1prong0pizeroUp", "pfmet_p4_recoilcorrected__tauEs1prong0pizeroUp");
    auto df102 = quantities::pt(df101, "pfmet__jesUncBBEC1YearUp", "pfmet_p4_recoilcorrected__jesUncBBEC1YearUp");
    auto df103 = quantities::pt(df102, "pfmet__jesUncHEMIssueUp", "pfmet_p4_recoilcorrected__jesUncHEMIssueUp");
    auto df104 = quantities::pt(df103, "pfmet__jesUncRelativeSampleYearDown", "pfmet_p4_recoilcorrected__jesUncRelativeSampleYearDown");
    auto df105 = quantities::pt(df104, "pfmet__jesUncHFUp", "pfmet_p4_recoilcorrected__jesUncHFUp");
    auto df106 = quantities::pt(df105, "pfmet__tauEs1prong0pizeroDown", "pfmet_p4_recoilcorrected__tauEs1prong0pizeroDown");
    auto df107 = quantities::pt(df106, "pfmet__tauEs1prong1pizeroDown", "pfmet_p4_recoilcorrected__tauEs1prong1pizeroDown");
    auto df108 = quantities::pt(df107, "pfmet__jesUncFlavorQCDDown", "pfmet_p4_recoilcorrected__jesUncFlavorQCDDown");
    auto df109 = quantities::pt(df108, "pfmet__jesUncHEMIssueDown", "pfmet_p4_recoilcorrected__jesUncHEMIssueDown");
    auto df110 = quantities::pt(df109, "pfmet__jesUncAbsoluteUp", "pfmet_p4_recoilcorrected__jesUncAbsoluteUp");
    auto df111 = quantities::pt(df110, "pfmet__jesUncEC2YearUp", "pfmet_p4_recoilcorrected__jesUncEC2YearUp");
    auto df112 = quantities::pt(df111, "pfmet__tauEs3prong0pizeroUp", "pfmet_p4_recoilcorrected__tauEs3prong0pizeroUp");
    auto df113 = quantities::pt(df112, "pfmet__jesUncBBEC1Up", "pfmet_p4_recoilcorrected__jesUncBBEC1Up");
    auto df114 = quantities::pt(df113, "pfmet__jesUncEC2Up", "pfmet_p4_recoilcorrected__jesUncEC2Up");
    auto df115 = quantities::pt(df114, "pfmet__jesUncAbsoluteYearUp", "pfmet_p4_recoilcorrected__jesUncAbsoluteYearUp");
    auto df116 = quantities::pt(df115, "pfmet__jesUncHFYearUp", "pfmet_p4_recoilcorrected__jesUncHFYearUp");
    auto df117 = quantities::pt(df116, "pfmet__jesUncHFYearDown", "pfmet_p4_recoilcorrected__jesUncHFYearDown");
    auto df118 = quantities::pt(df117, "pfmet__tauEs3prong1pizeroUp", "pfmet_p4_recoilcorrected__tauEs3prong1pizeroUp");
    auto df119 = quantities::pt(df118, "pfmet__jesUncBBEC1YearDown", "pfmet_p4_recoilcorrected__jesUncBBEC1YearDown");
    auto df120 = quantities::pt(df119, "pfmet__tauEs3prong0pizeroDown", "pfmet_p4_recoilcorrected__tauEs3prong0pizeroDown");
    auto df121 = quantities::phi(df120, "pfmetphi", "pfmet_p4_recoilcorrected");
    auto df122 = quantities::phi(df121, "pfmetphi__jesUncFlavorQCDUp", "pfmet_p4_recoilcorrected__jesUncFlavorQCDUp");
    auto df123 = quantities::phi(df122, "pfmetphi__jesUncHFDown", "pfmet_p4_recoilcorrected__jesUncHFDown");
    auto df124 = quantities::phi(df123, "pfmetphi__jesUncRelativeBalUp", "pfmet_p4_recoilcorrected__jesUncRelativeBalUp");
    auto df125 = quantities::phi(df124, "pfmetphi__jesUncTotalDown", "pfmet_p4_recoilcorrected__jesUncTotalDown");
    auto df126 = quantities::phi(df125, "pfmetphi__jesUncRelativeSampleYearUp", "pfmet_p4_recoilcorrected__jesUncRelativeSampleYearUp");
    auto df127 = quantities::phi(df126, "pfmetphi__jesUncAbsoluteDown", "pfmet_p4_recoilcorrected__jesUncAbsoluteDown");
    auto df128 = quantities::phi(df127, "pfmetphi__tauEs1prong1pizeroUp", "pfmet_p4_recoilcorrected__tauEs1prong1pizeroUp");
    auto df129 = quantities::phi(df128, "pfmetphi__jerUncUp", "pfmet_p4_recoilcorrected__jerUncUp");
    auto df130 = quantities::phi(df129, "pfmetphi__jerUncDown", "pfmet_p4_recoilcorrected__jerUncDown");
    auto df131 = quantities::phi(df130, "pfmetphi__jesUncEC2YearDown", "pfmet_p4_recoilcorrected__jesUncEC2YearDown");
    auto df132 = quantities::phi(df131, "pfmetphi__jesUncBBEC1Down", "pfmet_p4_recoilcorrected__jesUncBBEC1Down");
    auto df133 = quantities::phi(df132, "pfmetphi__jesUncEC2Down", "pfmet_p4_recoilcorrected__jesUncEC2Down");
    auto df134 = quantities::phi(df133, "pfmetphi__tauEs3prong1pizeroDown", "pfmet_p4_recoilcorrected__tauEs3prong1pizeroDown");
    auto df135 = quantities::phi(df134, "pfmetphi__jesUncAbsoluteYearDown", "pfmet_p4_recoilcorrected__jesUncAbsoluteYearDown");
    auto df136 = quantities::phi(df135, "pfmetphi__jesUncRelativeBalDown", "pfmet_p4_recoilcorrected__jesUncRelativeBalDown");
    auto df137 = quantities::phi(df136, "pfmetphi__jesUncTotalUp", "pfmet_p4_recoilcorrected__jesUncTotalUp");
    auto df138 = quantities::phi(df137, "pfmetphi__tauEs1prong0pizeroUp", "pfmet_p4_recoilcorrected__tauEs1prong0pizeroUp");
    auto df139 = quantities::phi(df138, "pfmetphi__jesUncBBEC1YearUp", "pfmet_p4_recoilcorrected__jesUncBBEC1YearUp");
    auto df140 = quantities::phi(df139, "pfmetphi__jesUncHEMIssueUp", "pfmet_p4_recoilcorrected__jesUncHEMIssueUp");
    auto df141 = quantities::phi(df140, "pfmetphi__jesUncRelativeSampleYearDown", "pfmet_p4_recoilcorrected__jesUncRelativeSampleYearDown");
    auto df142 = quantities::phi(df141, "pfmetphi__jesUncHFUp", "pfmet_p4_recoilcorrected__jesUncHFUp");
    auto df143 = quantities::phi(df142, "pfmetphi__tauEs1prong0pizeroDown", "pfmet_p4_recoilcorrected__tauEs1prong0pizeroDown");
    auto df144 = quantities::phi(df143, "pfmetphi__tauEs1prong1pizeroDown", "pfmet_p4_recoilcorrected__tauEs1prong1pizeroDown");
    auto df145 = quantities::phi(df144, "pfmetphi__jesUncFlavorQCDDown", "pfmet_p4_recoilcorrected__jesUncFlavorQCDDown");
    auto df146 = quantities::phi(df145, "pfmetphi__jesUncHEMIssueDown", "pfmet_p4_recoilcorrected__jesUncHEMIssueDown");
    auto df147 = quantities::phi(df146, "pfmetphi__jesUncAbsoluteUp", "pfmet_p4_recoilcorrected__jesUncAbsoluteUp");
    auto df148 = quantities::phi(df147, "pfmetphi__jesUncEC2YearUp", "pfmet_p4_recoilcorrected__jesUncEC2YearUp");
    auto df149 = quantities::phi(df148, "pfmetphi__tauEs3prong0pizeroUp", "pfmet_p4_recoilcorrected__tauEs3prong0pizeroUp");
    auto df150 = quantities::phi(df149, "pfmetphi__jesUncBBEC1Up", "pfmet_p4_recoilcorrected__jesUncBBEC1Up");
    auto df151 = quantities::phi(df150, "pfmetphi__jesUncEC2Up", "pfmet_p4_recoilcorrected__jesUncEC2Up");
    auto df152 = quantities::phi(df151, "pfmetphi__jesUncAbsoluteYearUp", "pfmet_p4_recoilcorrected__jesUncAbsoluteYearUp");
    auto df153 = quantities::phi(df152, "pfmetphi__jesUncHFYearUp", "pfmet_p4_recoilcorrected__jesUncHFYearUp");
    auto df154 = quantities::phi(df153, "pfmetphi__jesUncHFYearDown", "pfmet_p4_recoilcorrected__jesUncHFYearDown");
    auto df155 = quantities::phi(df154, "pfmetphi__tauEs3prong1pizeroUp", "pfmet_p4_recoilcorrected__tauEs3prong1pizeroUp");
    auto df156 = quantities::phi(df155, "pfmetphi__jesUncBBEC1YearDown", "pfmet_p4_recoilcorrected__jesUncBBEC1YearDown");
    auto df157 = quantities::phi(df156, "pfmetphi__tauEs3prong0pizeroDown", "pfmet_p4_recoilcorrected__tauEs3prong0pizeroDown");
    return df157;

}
