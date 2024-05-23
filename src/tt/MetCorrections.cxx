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
ROOT::RDF::RNode MetCorrections_tt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = met::propagateLeptonsToMet(df0, "met_p4", "p4_1_uncorrected", "p4_2_uncorrected", "p4_1", "p4_2", "met_p4_leptoncorrected", true);
    auto df2 = met::propagateLeptonsToMet(df1, "met_p4__metUnclusteredEnDown", "p4_1_uncorrected", "p4_2_uncorrected", "p4_1", "p4_2", "met_p4_leptoncorrected__metUnclusteredEnDown", true);
    auto df3 = met::propagateLeptonsToMet(df2, "met_p4", "p4_1_uncorrected__tauEs3prong1pizeroDown", "p4_2_uncorrected__tauEs3prong1pizeroDown", "p4_1__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown", "met_p4_leptoncorrected__tauEs3prong1pizeroDown", true);
    auto df4 = met::propagateLeptonsToMet(df3, "met_p4", "p4_1_uncorrected__tauEs1prong0pizeroDown", "p4_2_uncorrected__tauEs1prong0pizeroDown", "p4_1__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown", "met_p4_leptoncorrected__tauEs1prong0pizeroDown", true);
    auto df5 = met::propagateLeptonsToMet(df4, "met_p4", "p4_1_uncorrected__tauEs3prong1pizeroUp", "p4_2_uncorrected__tauEs3prong1pizeroUp", "p4_1__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp", "met_p4_leptoncorrected__tauEs3prong1pizeroUp", true);
    auto df6 = met::propagateLeptonsToMet(df5, "met_p4", "p4_1_uncorrected__tauEs1prong1pizeroDown", "p4_2_uncorrected__tauEs1prong1pizeroDown", "p4_1__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown", "met_p4_leptoncorrected__tauEs1prong1pizeroDown", true);
    auto df7 = met::propagateLeptonsToMet(df6, "met_p4", "p4_1_uncorrected__tauEs1prong1pizeroUp", "p4_2_uncorrected__tauEs1prong1pizeroUp", "p4_1__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp", "met_p4_leptoncorrected__tauEs1prong1pizeroUp", true);
    auto df8 = met::propagateLeptonsToMet(df7, "met_p4", "p4_1_uncorrected__tauEs1prong0pizeroUp", "p4_2_uncorrected__tauEs1prong0pizeroUp", "p4_1__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp", "met_p4_leptoncorrected__tauEs1prong0pizeroUp", true);
    auto df9 = met::propagateLeptonsToMet(df8, "met_p4", "p4_1_uncorrected__tauEs3prong0pizeroDown", "p4_2_uncorrected__tauEs3prong0pizeroDown", "p4_1__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown", "met_p4_leptoncorrected__tauEs3prong0pizeroDown", true);
    auto df10 = met::propagateLeptonsToMet(df9, "met_p4", "p4_1_uncorrected__tauEs3prong0pizeroUp", "p4_2_uncorrected__tauEs3prong0pizeroUp", "p4_1__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp", "met_p4_leptoncorrected__tauEs3prong0pizeroUp", true);
    auto df11 = met::propagateLeptonsToMet(df10, "met_p4__metUnclusteredEnUp", "p4_1_uncorrected", "p4_2_uncorrected", "p4_1", "p4_2", "met_p4_leptoncorrected__metUnclusteredEnUp", true);
    auto df12 = met::propagateJetsToMet(df11, "met_p4_leptoncorrected", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected", true, 15);
    auto df13 = met::propagateJetsToMet(df12, "met_p4_leptoncorrected__metUnclusteredEnDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__metUnclusteredEnDown", true, 15);
    auto df14 = met::propagateJetsToMet(df13, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncFlavorQCDUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncFlavorQCDUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncFlavorQCDUp", true, 15);
    auto df15 = met::propagateJetsToMet(df14, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHFDown", true, 15);
    auto df16 = met::propagateJetsToMet(df15, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeBalUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeBalUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncRelativeBalUp", true, 15);
    auto df17 = met::propagateJetsToMet(df16, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncTotalDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncTotalDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncTotalDown", true, 15);
    auto df18 = met::propagateJetsToMet(df17, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeSampleYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeSampleYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncRelativeSampleYearUp", true, 15);
    auto df19 = met::propagateJetsToMet(df18, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncAbsoluteDown", true, 15);
    auto df20 = met::propagateJetsToMet(df19, "met_p4_leptoncorrected__tauEs1prong1pizeroUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__tauEs1prong1pizeroUp", true, 15);
    auto df21 = met::propagateJetsToMet(df20, "met_p4_leptoncorrected", "Jet_pt_corrected__jerUncUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jerUncUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jerUncUp", true, 15);
    auto df22 = met::propagateJetsToMet(df21, "met_p4_leptoncorrected", "Jet_pt_corrected__jerUncDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jerUncDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jerUncDown", true, 15);
    auto df23 = met::propagateJetsToMet(df22, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2YearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2YearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncEC2YearDown", true, 15);
    auto df24 = met::propagateJetsToMet(df23, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1Down", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1Down", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncBBEC1Down", true, 15);
    auto df25 = met::propagateJetsToMet(df24, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2Down", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2Down", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncEC2Down", true, 15);
    auto df26 = met::propagateJetsToMet(df25, "met_p4_leptoncorrected__tauEs3prong1pizeroDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__tauEs3prong1pizeroDown", true, 15);
    auto df27 = met::propagateJetsToMet(df26, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncAbsoluteYearDown", true, 15);
    auto df28 = met::propagateJetsToMet(df27, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeBalDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeBalDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncRelativeBalDown", true, 15);
    auto df29 = met::propagateJetsToMet(df28, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncTotalUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncTotalUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncTotalUp", true, 15);
    auto df30 = met::propagateJetsToMet(df29, "met_p4_leptoncorrected__tauEs1prong0pizeroUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__tauEs1prong0pizeroUp", true, 15);
    auto df31 = met::propagateJetsToMet(df30, "met_p4_leptoncorrected__metUnclusteredEnUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__metUnclusteredEnUp", true, 15);
    auto df32 = met::propagateJetsToMet(df31, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1YearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1YearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncBBEC1YearUp", true, 15);
    auto df33 = met::propagateJetsToMet(df32, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHEMIssueUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHEMIssueUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHEMIssueUp", true, 15);
    auto df34 = met::propagateJetsToMet(df33, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeSampleYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeSampleYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncRelativeSampleYearDown", true, 15);
    auto df35 = met::propagateJetsToMet(df34, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHFUp", true, 15);
    auto df36 = met::propagateJetsToMet(df35, "met_p4_leptoncorrected__tauEs1prong0pizeroDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__tauEs1prong0pizeroDown", true, 15);
    auto df37 = met::propagateJetsToMet(df36, "met_p4_leptoncorrected__tauEs1prong1pizeroDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__tauEs1prong1pizeroDown", true, 15);
    auto df38 = met::propagateJetsToMet(df37, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncFlavorQCDDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncFlavorQCDDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncFlavorQCDDown", true, 15);
    auto df39 = met::propagateJetsToMet(df38, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHEMIssueDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHEMIssueDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHEMIssueDown", true, 15);
    auto df40 = met::propagateJetsToMet(df39, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncAbsoluteUp", true, 15);
    auto df41 = met::propagateJetsToMet(df40, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2YearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2YearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncEC2YearUp", true, 15);
    auto df42 = met::propagateJetsToMet(df41, "met_p4_leptoncorrected__tauEs3prong0pizeroUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__tauEs3prong0pizeroUp", true, 15);
    auto df43 = met::propagateJetsToMet(df42, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1Up", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1Up", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncBBEC1Up", true, 15);
    auto df44 = met::propagateJetsToMet(df43, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2Up", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2Up", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncEC2Up", true, 15);
    auto df45 = met::propagateJetsToMet(df44, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncAbsoluteYearUp", true, 15);
    auto df46 = met::propagateJetsToMet(df45, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHFYearUp", true, 15);
    auto df47 = met::propagateJetsToMet(df46, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHFYearDown", true, 15);
    auto df48 = met::propagateJetsToMet(df47, "met_p4_leptoncorrected__tauEs3prong1pizeroUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__tauEs3prong1pizeroUp", true, 15);
    auto df49 = met::propagateJetsToMet(df48, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1YearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1YearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncBBEC1YearDown", true, 15);
    auto df50 = met::propagateJetsToMet(df49, "met_p4_leptoncorrected__tauEs3prong0pizeroDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__tauEs3prong0pizeroDown", true, 15);
    auto df51 = met::applyRecoilCorrections(df50, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df52 = met::applyRecoilCorrections(df51, "met_p4_jetcorrected__metUnclusteredEnDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metUnclusteredEnDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df53 = met::applyRecoilCorrections(df52, "met_p4_jetcorrected__jesUncFlavorQCDUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncFlavorQCDUp", "met_p4_recoilcorrected__jesUncFlavorQCDUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df54 = met::applyRecoilCorrections(df53, "met_p4_jetcorrected__jesUncHFDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFDown", "met_p4_recoilcorrected__jesUncHFDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df55 = met::applyRecoilCorrections(df54, "met_p4_jetcorrected__jesUncRelativeBalUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeBalUp", "met_p4_recoilcorrected__jesUncRelativeBalUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df56 = met::applyRecoilCorrections(df55, "met_p4_jetcorrected__jesUncTotalDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncTotalDown", "met_p4_recoilcorrected__jesUncTotalDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df57 = met::applyRecoilCorrections(df56, "met_p4_jetcorrected__jesUncRelativeSampleYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeSampleYearUp", "met_p4_recoilcorrected__jesUncRelativeSampleYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df58 = met::applyRecoilCorrections(df57, "met_p4_jetcorrected__jesUncAbsoluteDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteDown", "met_p4_recoilcorrected__jesUncAbsoluteDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df59 = met::applyRecoilCorrections(df58, "met_p4_jetcorrected__tauEs1prong1pizeroUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__tauEs1prong1pizeroUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df60 = met::applyRecoilCorrections(df59, "met_p4_jetcorrected__jerUncUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jerUncUp", "met_p4_recoilcorrected__jerUncUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df61 = met::applyRecoilCorrections(df60, "met_p4_jetcorrected__jerUncDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jerUncDown", "met_p4_recoilcorrected__jerUncDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df62 = met::applyRecoilCorrections(df61, "met_p4_jetcorrected__jesUncEC2YearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2YearDown", "met_p4_recoilcorrected__jesUncEC2YearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df63 = met::applyRecoilCorrections(df62, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metRecoilResolutionUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, true, false, true, false, false);
    auto df64 = met::applyRecoilCorrections(df63, "met_p4_jetcorrected__jesUncBBEC1Down", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1Down", "met_p4_recoilcorrected__jesUncBBEC1Down", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df65 = met::applyRecoilCorrections(df64, "met_p4_jetcorrected__jesUncEC2Down", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2Down", "met_p4_recoilcorrected__jesUncEC2Down", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df66 = met::applyRecoilCorrections(df65, "met_p4_jetcorrected__tauEs3prong1pizeroDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__tauEs3prong1pizeroDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df67 = met::applyRecoilCorrections(df66, "met_p4_jetcorrected__jesUncAbsoluteYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteYearDown", "met_p4_recoilcorrected__jesUncAbsoluteYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df68 = met::applyRecoilCorrections(df67, "met_p4_jetcorrected__jesUncRelativeBalDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeBalDown", "met_p4_recoilcorrected__jesUncRelativeBalDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df69 = met::applyRecoilCorrections(df68, "met_p4_jetcorrected__jesUncTotalUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncTotalUp", "met_p4_recoilcorrected__jesUncTotalUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df70 = met::applyRecoilCorrections(df69, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metRecoilResponseUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, true, true, false, false);
    auto df71 = met::applyRecoilCorrections(df70, "met_p4_jetcorrected__tauEs1prong0pizeroUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__tauEs1prong0pizeroUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df72 = met::applyRecoilCorrections(df71, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metRecoilResolutionDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, true, false, false, true, false);
    auto df73 = met::applyRecoilCorrections(df72, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metRecoilResponseDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, true, false, true, false);
    auto df74 = met::applyRecoilCorrections(df73, "met_p4_jetcorrected__metUnclusteredEnUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metUnclusteredEnUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df75 = met::applyRecoilCorrections(df74, "met_p4_jetcorrected__jesUncBBEC1YearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1YearUp", "met_p4_recoilcorrected__jesUncBBEC1YearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df76 = met::applyRecoilCorrections(df75, "met_p4_jetcorrected__jesUncHEMIssueUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHEMIssueUp", "met_p4_recoilcorrected__jesUncHEMIssueUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df77 = met::applyRecoilCorrections(df76, "met_p4_jetcorrected__jesUncRelativeSampleYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeSampleYearDown", "met_p4_recoilcorrected__jesUncRelativeSampleYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df78 = met::applyRecoilCorrections(df77, "met_p4_jetcorrected__jesUncHFUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFUp", "met_p4_recoilcorrected__jesUncHFUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df79 = met::applyRecoilCorrections(df78, "met_p4_jetcorrected__tauEs1prong0pizeroDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__tauEs1prong0pizeroDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df80 = met::applyRecoilCorrections(df79, "met_p4_jetcorrected__tauEs1prong1pizeroDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__tauEs1prong1pizeroDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df81 = met::applyRecoilCorrections(df80, "met_p4_jetcorrected__jesUncFlavorQCDDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncFlavorQCDDown", "met_p4_recoilcorrected__jesUncFlavorQCDDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df82 = met::applyRecoilCorrections(df81, "met_p4_jetcorrected__jesUncHEMIssueDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHEMIssueDown", "met_p4_recoilcorrected__jesUncHEMIssueDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df83 = met::applyRecoilCorrections(df82, "met_p4_jetcorrected__jesUncAbsoluteUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteUp", "met_p4_recoilcorrected__jesUncAbsoluteUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df84 = met::applyRecoilCorrections(df83, "met_p4_jetcorrected__jesUncEC2YearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2YearUp", "met_p4_recoilcorrected__jesUncEC2YearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df85 = met::applyRecoilCorrections(df84, "met_p4_jetcorrected__tauEs3prong0pizeroUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__tauEs3prong0pizeroUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df86 = met::applyRecoilCorrections(df85, "met_p4_jetcorrected__jesUncBBEC1Up", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1Up", "met_p4_recoilcorrected__jesUncBBEC1Up", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df87 = met::applyRecoilCorrections(df86, "met_p4_jetcorrected__jesUncEC2Up", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2Up", "met_p4_recoilcorrected__jesUncEC2Up", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df88 = met::applyRecoilCorrections(df87, "met_p4_jetcorrected__jesUncAbsoluteYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteYearUp", "met_p4_recoilcorrected__jesUncAbsoluteYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df89 = met::applyRecoilCorrections(df88, "met_p4_jetcorrected__jesUncHFYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFYearUp", "met_p4_recoilcorrected__jesUncHFYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df90 = met::applyRecoilCorrections(df89, "met_p4_jetcorrected__jesUncHFYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFYearDown", "met_p4_recoilcorrected__jesUncHFYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df91 = met::applyRecoilCorrections(df90, "met_p4_jetcorrected__tauEs3prong1pizeroUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__tauEs3prong1pizeroUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df92 = met::applyRecoilCorrections(df91, "met_p4_jetcorrected__jesUncBBEC1YearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1YearDown", "met_p4_recoilcorrected__jesUncBBEC1YearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df93 = met::applyRecoilCorrections(df92, "met_p4_jetcorrected__tauEs3prong0pizeroDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__tauEs3prong0pizeroDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df94 = quantities::pt(df93, "met", "met_p4_recoilcorrected");
    auto df95 = quantities::pt(df94, "met__metUnclusteredEnDown", "met_p4_recoilcorrected__metUnclusteredEnDown");
    auto df96 = quantities::pt(df95, "met__jesUncFlavorQCDUp", "met_p4_recoilcorrected__jesUncFlavorQCDUp");
    auto df97 = quantities::pt(df96, "met__jesUncHFDown", "met_p4_recoilcorrected__jesUncHFDown");
    auto df98 = quantities::pt(df97, "met__jesUncRelativeBalUp", "met_p4_recoilcorrected__jesUncRelativeBalUp");
    auto df99 = quantities::pt(df98, "met__jesUncTotalDown", "met_p4_recoilcorrected__jesUncTotalDown");
    auto df100 = quantities::pt(df99, "met__jesUncRelativeSampleYearUp", "met_p4_recoilcorrected__jesUncRelativeSampleYearUp");
    auto df101 = quantities::pt(df100, "met__jesUncAbsoluteDown", "met_p4_recoilcorrected__jesUncAbsoluteDown");
    auto df102 = quantities::pt(df101, "met__tauEs1prong1pizeroUp", "met_p4_recoilcorrected__tauEs1prong1pizeroUp");
    auto df103 = quantities::pt(df102, "met__jerUncUp", "met_p4_recoilcorrected__jerUncUp");
    auto df104 = quantities::pt(df103, "met__jerUncDown", "met_p4_recoilcorrected__jerUncDown");
    auto df105 = quantities::pt(df104, "met__jesUncEC2YearDown", "met_p4_recoilcorrected__jesUncEC2YearDown");
    auto df106 = quantities::pt(df105, "met__metRecoilResolutionUp", "met_p4_recoilcorrected__metRecoilResolutionUp");
    auto df107 = quantities::pt(df106, "met__jesUncBBEC1Down", "met_p4_recoilcorrected__jesUncBBEC1Down");
    auto df108 = quantities::pt(df107, "met__jesUncEC2Down", "met_p4_recoilcorrected__jesUncEC2Down");
    auto df109 = quantities::pt(df108, "met__tauEs3prong1pizeroDown", "met_p4_recoilcorrected__tauEs3prong1pizeroDown");
    auto df110 = quantities::pt(df109, "met__jesUncAbsoluteYearDown", "met_p4_recoilcorrected__jesUncAbsoluteYearDown");
    auto df111 = quantities::pt(df110, "met__jesUncRelativeBalDown", "met_p4_recoilcorrected__jesUncRelativeBalDown");
    auto df112 = quantities::pt(df111, "met__jesUncTotalUp", "met_p4_recoilcorrected__jesUncTotalUp");
    auto df113 = quantities::pt(df112, "met__metRecoilResponseUp", "met_p4_recoilcorrected__metRecoilResponseUp");
    auto df114 = quantities::pt(df113, "met__tauEs1prong0pizeroUp", "met_p4_recoilcorrected__tauEs1prong0pizeroUp");
    auto df115 = quantities::pt(df114, "met__metRecoilResolutionDown", "met_p4_recoilcorrected__metRecoilResolutionDown");
    auto df116 = quantities::pt(df115, "met__metRecoilResponseDown", "met_p4_recoilcorrected__metRecoilResponseDown");
    auto df117 = quantities::pt(df116, "met__metUnclusteredEnUp", "met_p4_recoilcorrected__metUnclusteredEnUp");
    auto df118 = quantities::pt(df117, "met__jesUncBBEC1YearUp", "met_p4_recoilcorrected__jesUncBBEC1YearUp");
    auto df119 = quantities::pt(df118, "met__jesUncHEMIssueUp", "met_p4_recoilcorrected__jesUncHEMIssueUp");
    auto df120 = quantities::pt(df119, "met__jesUncRelativeSampleYearDown", "met_p4_recoilcorrected__jesUncRelativeSampleYearDown");
    auto df121 = quantities::pt(df120, "met__jesUncHFUp", "met_p4_recoilcorrected__jesUncHFUp");
    auto df122 = quantities::pt(df121, "met__tauEs1prong0pizeroDown", "met_p4_recoilcorrected__tauEs1prong0pizeroDown");
    auto df123 = quantities::pt(df122, "met__tauEs1prong1pizeroDown", "met_p4_recoilcorrected__tauEs1prong1pizeroDown");
    auto df124 = quantities::pt(df123, "met__jesUncFlavorQCDDown", "met_p4_recoilcorrected__jesUncFlavorQCDDown");
    auto df125 = quantities::pt(df124, "met__jesUncHEMIssueDown", "met_p4_recoilcorrected__jesUncHEMIssueDown");
    auto df126 = quantities::pt(df125, "met__jesUncAbsoluteUp", "met_p4_recoilcorrected__jesUncAbsoluteUp");
    auto df127 = quantities::pt(df126, "met__jesUncEC2YearUp", "met_p4_recoilcorrected__jesUncEC2YearUp");
    auto df128 = quantities::pt(df127, "met__tauEs3prong0pizeroUp", "met_p4_recoilcorrected__tauEs3prong0pizeroUp");
    auto df129 = quantities::pt(df128, "met__jesUncBBEC1Up", "met_p4_recoilcorrected__jesUncBBEC1Up");
    auto df130 = quantities::pt(df129, "met__jesUncEC2Up", "met_p4_recoilcorrected__jesUncEC2Up");
    auto df131 = quantities::pt(df130, "met__jesUncAbsoluteYearUp", "met_p4_recoilcorrected__jesUncAbsoluteYearUp");
    auto df132 = quantities::pt(df131, "met__jesUncHFYearUp", "met_p4_recoilcorrected__jesUncHFYearUp");
    auto df133 = quantities::pt(df132, "met__jesUncHFYearDown", "met_p4_recoilcorrected__jesUncHFYearDown");
    auto df134 = quantities::pt(df133, "met__tauEs3prong1pizeroUp", "met_p4_recoilcorrected__tauEs3prong1pizeroUp");
    auto df135 = quantities::pt(df134, "met__jesUncBBEC1YearDown", "met_p4_recoilcorrected__jesUncBBEC1YearDown");
    auto df136 = quantities::pt(df135, "met__tauEs3prong0pizeroDown", "met_p4_recoilcorrected__tauEs3prong0pizeroDown");
    auto df137 = quantities::phi(df136, "metphi", "met_p4_recoilcorrected");
    auto df138 = quantities::phi(df137, "metphi__metUnclusteredEnDown", "met_p4_recoilcorrected__metUnclusteredEnDown");
    auto df139 = quantities::phi(df138, "metphi__jesUncFlavorQCDUp", "met_p4_recoilcorrected__jesUncFlavorQCDUp");
    auto df140 = quantities::phi(df139, "metphi__jesUncHFDown", "met_p4_recoilcorrected__jesUncHFDown");
    auto df141 = quantities::phi(df140, "metphi__jesUncRelativeBalUp", "met_p4_recoilcorrected__jesUncRelativeBalUp");
    auto df142 = quantities::phi(df141, "metphi__jesUncTotalDown", "met_p4_recoilcorrected__jesUncTotalDown");
    auto df143 = quantities::phi(df142, "metphi__jesUncRelativeSampleYearUp", "met_p4_recoilcorrected__jesUncRelativeSampleYearUp");
    auto df144 = quantities::phi(df143, "metphi__jesUncAbsoluteDown", "met_p4_recoilcorrected__jesUncAbsoluteDown");
    auto df145 = quantities::phi(df144, "metphi__tauEs1prong1pizeroUp", "met_p4_recoilcorrected__tauEs1prong1pizeroUp");
    auto df146 = quantities::phi(df145, "metphi__jerUncUp", "met_p4_recoilcorrected__jerUncUp");
    auto df147 = quantities::phi(df146, "metphi__jerUncDown", "met_p4_recoilcorrected__jerUncDown");
    auto df148 = quantities::phi(df147, "metphi__jesUncEC2YearDown", "met_p4_recoilcorrected__jesUncEC2YearDown");
    auto df149 = quantities::phi(df148, "metphi__metRecoilResolutionUp", "met_p4_recoilcorrected__metRecoilResolutionUp");
    auto df150 = quantities::phi(df149, "metphi__jesUncBBEC1Down", "met_p4_recoilcorrected__jesUncBBEC1Down");
    auto df151 = quantities::phi(df150, "metphi__jesUncEC2Down", "met_p4_recoilcorrected__jesUncEC2Down");
    auto df152 = quantities::phi(df151, "metphi__tauEs3prong1pizeroDown", "met_p4_recoilcorrected__tauEs3prong1pizeroDown");
    auto df153 = quantities::phi(df152, "metphi__jesUncAbsoluteYearDown", "met_p4_recoilcorrected__jesUncAbsoluteYearDown");
    auto df154 = quantities::phi(df153, "metphi__jesUncRelativeBalDown", "met_p4_recoilcorrected__jesUncRelativeBalDown");
    auto df155 = quantities::phi(df154, "metphi__jesUncTotalUp", "met_p4_recoilcorrected__jesUncTotalUp");
    auto df156 = quantities::phi(df155, "metphi__metRecoilResponseUp", "met_p4_recoilcorrected__metRecoilResponseUp");
    auto df157 = quantities::phi(df156, "metphi__tauEs1prong0pizeroUp", "met_p4_recoilcorrected__tauEs1prong0pizeroUp");
    auto df158 = quantities::phi(df157, "metphi__metRecoilResolutionDown", "met_p4_recoilcorrected__metRecoilResolutionDown");
    auto df159 = quantities::phi(df158, "metphi__metRecoilResponseDown", "met_p4_recoilcorrected__metRecoilResponseDown");
    auto df160 = quantities::phi(df159, "metphi__metUnclusteredEnUp", "met_p4_recoilcorrected__metUnclusteredEnUp");
    auto df161 = quantities::phi(df160, "metphi__jesUncBBEC1YearUp", "met_p4_recoilcorrected__jesUncBBEC1YearUp");
    auto df162 = quantities::phi(df161, "metphi__jesUncHEMIssueUp", "met_p4_recoilcorrected__jesUncHEMIssueUp");
    auto df163 = quantities::phi(df162, "metphi__jesUncRelativeSampleYearDown", "met_p4_recoilcorrected__jesUncRelativeSampleYearDown");
    auto df164 = quantities::phi(df163, "metphi__jesUncHFUp", "met_p4_recoilcorrected__jesUncHFUp");
    auto df165 = quantities::phi(df164, "metphi__tauEs1prong0pizeroDown", "met_p4_recoilcorrected__tauEs1prong0pizeroDown");
    auto df166 = quantities::phi(df165, "metphi__tauEs1prong1pizeroDown", "met_p4_recoilcorrected__tauEs1prong1pizeroDown");
    auto df167 = quantities::phi(df166, "metphi__jesUncFlavorQCDDown", "met_p4_recoilcorrected__jesUncFlavorQCDDown");
    auto df168 = quantities::phi(df167, "metphi__jesUncHEMIssueDown", "met_p4_recoilcorrected__jesUncHEMIssueDown");
    auto df169 = quantities::phi(df168, "metphi__jesUncAbsoluteUp", "met_p4_recoilcorrected__jesUncAbsoluteUp");
    auto df170 = quantities::phi(df169, "metphi__jesUncEC2YearUp", "met_p4_recoilcorrected__jesUncEC2YearUp");
    auto df171 = quantities::phi(df170, "metphi__tauEs3prong0pizeroUp", "met_p4_recoilcorrected__tauEs3prong0pizeroUp");
    auto df172 = quantities::phi(df171, "metphi__jesUncBBEC1Up", "met_p4_recoilcorrected__jesUncBBEC1Up");
    auto df173 = quantities::phi(df172, "metphi__jesUncEC2Up", "met_p4_recoilcorrected__jesUncEC2Up");
    auto df174 = quantities::phi(df173, "metphi__jesUncAbsoluteYearUp", "met_p4_recoilcorrected__jesUncAbsoluteYearUp");
    auto df175 = quantities::phi(df174, "metphi__jesUncHFYearUp", "met_p4_recoilcorrected__jesUncHFYearUp");
    auto df176 = quantities::phi(df175, "metphi__jesUncHFYearDown", "met_p4_recoilcorrected__jesUncHFYearDown");
    auto df177 = quantities::phi(df176, "metphi__tauEs3prong1pizeroUp", "met_p4_recoilcorrected__tauEs3prong1pizeroUp");
    auto df178 = quantities::phi(df177, "metphi__jesUncBBEC1YearDown", "met_p4_recoilcorrected__jesUncBBEC1YearDown");
    auto df179 = quantities::phi(df178, "metphi__tauEs3prong0pizeroDown", "met_p4_recoilcorrected__tauEs3prong0pizeroDown");
    return df179;

}
