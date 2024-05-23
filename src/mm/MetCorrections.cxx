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
ROOT::RDF::RNode MetCorrections_mm (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = met::propagateLeptonsToMet(df0, "met_p4", "p4_1_uncorrected", "p4_2_uncorrected", "p4_1", "p4_2", "met_p4_leptoncorrected", true);
    auto df2 = met::propagateLeptonsToMet(df1, "met_p4__metUnclusteredEnDown", "p4_1_uncorrected", "p4_2_uncorrected", "p4_1", "p4_2", "met_p4_leptoncorrected__metUnclusteredEnDown", true);
    auto df3 = met::propagateLeptonsToMet(df2, "met_p4__metUnclusteredEnUp", "p4_1_uncorrected", "p4_2_uncorrected", "p4_1", "p4_2", "met_p4_leptoncorrected__metUnclusteredEnUp", true);
    auto df4 = met::propagateJetsToMet(df3, "met_p4_leptoncorrected", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected", true, 15);
    auto df5 = met::propagateJetsToMet(df4, "met_p4_leptoncorrected__metUnclusteredEnDown", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__metUnclusteredEnDown", true, 15);
    auto df6 = met::propagateJetsToMet(df5, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncFlavorQCDUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncFlavorQCDUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncFlavorQCDUp", true, 15);
    auto df7 = met::propagateJetsToMet(df6, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHFDown", true, 15);
    auto df8 = met::propagateJetsToMet(df7, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeBalUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeBalUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncRelativeBalUp", true, 15);
    auto df9 = met::propagateJetsToMet(df8, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncTotalDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncTotalDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncTotalDown", true, 15);
    auto df10 = met::propagateJetsToMet(df9, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeSampleYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeSampleYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncRelativeSampleYearUp", true, 15);
    auto df11 = met::propagateJetsToMet(df10, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncAbsoluteDown", true, 15);
    auto df12 = met::propagateJetsToMet(df11, "met_p4_leptoncorrected", "Jet_pt_corrected__jerUncDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jerUncDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jerUncDown", true, 15);
    auto df13 = met::propagateJetsToMet(df12, "met_p4_leptoncorrected", "Jet_pt_corrected__jerUncUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jerUncUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jerUncUp", true, 15);
    auto df14 = met::propagateJetsToMet(df13, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2YearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2YearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncEC2YearDown", true, 15);
    auto df15 = met::propagateJetsToMet(df14, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1Down", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1Down", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncBBEC1Down", true, 15);
    auto df16 = met::propagateJetsToMet(df15, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2Down", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2Down", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncEC2Down", true, 15);
    auto df17 = met::propagateJetsToMet(df16, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncAbsoluteYearDown", true, 15);
    auto df18 = met::propagateJetsToMet(df17, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeBalDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeBalDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncRelativeBalDown", true, 15);
    auto df19 = met::propagateJetsToMet(df18, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncTotalUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncTotalUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncTotalUp", true, 15);
    auto df20 = met::propagateJetsToMet(df19, "met_p4_leptoncorrected__metUnclusteredEnUp", "Jet_pt_corrected", "Jet_eta", "Jet_phi", "Jet_mass_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__metUnclusteredEnUp", true, 15);
    auto df21 = met::propagateJetsToMet(df20, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1YearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1YearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncBBEC1YearUp", true, 15);
    auto df22 = met::propagateJetsToMet(df21, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHEMIssueUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHEMIssueUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHEMIssueUp", true, 15);
    auto df23 = met::propagateJetsToMet(df22, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncRelativeSampleYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncRelativeSampleYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncRelativeSampleYearDown", true, 15);
    auto df24 = met::propagateJetsToMet(df23, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHFUp", true, 15);
    auto df25 = met::propagateJetsToMet(df24, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncFlavorQCDDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncFlavorQCDDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncFlavorQCDDown", true, 15);
    auto df26 = met::propagateJetsToMet(df25, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHEMIssueDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHEMIssueDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHEMIssueDown", true, 15);
    auto df27 = met::propagateJetsToMet(df26, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncAbsoluteUp", true, 15);
    auto df28 = met::propagateJetsToMet(df27, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2YearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2YearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncEC2YearUp", true, 15);
    auto df29 = met::propagateJetsToMet(df28, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncEC2Up", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncEC2Up", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncEC2Up", true, 15);
    auto df30 = met::propagateJetsToMet(df29, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1Up", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1Up", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncBBEC1Up", true, 15);
    auto df31 = met::propagateJetsToMet(df30, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncAbsoluteYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncAbsoluteYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncAbsoluteYearUp", true, 15);
    auto df32 = met::propagateJetsToMet(df31, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFYearUp", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHFYearUp", true, 15);
    auto df33 = met::propagateJetsToMet(df32, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncHFYearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncHFYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncHFYearDown", true, 15);
    auto df34 = met::propagateJetsToMet(df33, "met_p4_leptoncorrected", "Jet_pt_corrected__jesUncBBEC1YearDown", "Jet_eta", "Jet_phi", "Jet_mass_corrected__jesUncBBEC1YearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "met_p4_jetcorrected__jesUncBBEC1YearDown", true, 15);
    auto df35 = met::applyRecoilCorrections(df34, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df36 = met::applyRecoilCorrections(df35, "met_p4_jetcorrected__metUnclusteredEnDown", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metUnclusteredEnDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df37 = met::applyRecoilCorrections(df36, "met_p4_jetcorrected__jesUncFlavorQCDUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncFlavorQCDUp", "met_p4_recoilcorrected__jesUncFlavorQCDUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df38 = met::applyRecoilCorrections(df37, "met_p4_jetcorrected__jesUncHFDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFDown", "met_p4_recoilcorrected__jesUncHFDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df39 = met::applyRecoilCorrections(df38, "met_p4_jetcorrected__jesUncRelativeBalUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeBalUp", "met_p4_recoilcorrected__jesUncRelativeBalUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df40 = met::applyRecoilCorrections(df39, "met_p4_jetcorrected__jesUncTotalDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncTotalDown", "met_p4_recoilcorrected__jesUncTotalDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df41 = met::applyRecoilCorrections(df40, "met_p4_jetcorrected__jesUncRelativeSampleYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeSampleYearUp", "met_p4_recoilcorrected__jesUncRelativeSampleYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df42 = met::applyRecoilCorrections(df41, "met_p4_jetcorrected__jesUncAbsoluteDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteDown", "met_p4_recoilcorrected__jesUncAbsoluteDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df43 = met::applyRecoilCorrections(df42, "met_p4_jetcorrected__jerUncDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jerUncDown", "met_p4_recoilcorrected__jerUncDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df44 = met::applyRecoilCorrections(df43, "met_p4_jetcorrected__jerUncUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jerUncUp", "met_p4_recoilcorrected__jerUncUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df45 = met::applyRecoilCorrections(df44, "met_p4_jetcorrected__jesUncEC2YearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2YearDown", "met_p4_recoilcorrected__jesUncEC2YearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df46 = met::applyRecoilCorrections(df45, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metRecoilResolutionUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, true, false, true, false, false);
    auto df47 = met::applyRecoilCorrections(df46, "met_p4_jetcorrected__jesUncBBEC1Down", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1Down", "met_p4_recoilcorrected__jesUncBBEC1Down", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df48 = met::applyRecoilCorrections(df47, "met_p4_jetcorrected__jesUncEC2Down", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2Down", "met_p4_recoilcorrected__jesUncEC2Down", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df49 = met::applyRecoilCorrections(df48, "met_p4_jetcorrected__jesUncAbsoluteYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteYearDown", "met_p4_recoilcorrected__jesUncAbsoluteYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df50 = met::applyRecoilCorrections(df49, "met_p4_jetcorrected__jesUncRelativeBalDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeBalDown", "met_p4_recoilcorrected__jesUncRelativeBalDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df51 = met::applyRecoilCorrections(df50, "met_p4_jetcorrected__jesUncTotalUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncTotalUp", "met_p4_recoilcorrected__jesUncTotalUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df52 = met::applyRecoilCorrections(df51, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metRecoilResponseUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, true, true, false, false);
    auto df53 = met::applyRecoilCorrections(df52, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metRecoilResolutionDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, true, false, false, true, false);
    auto df54 = met::applyRecoilCorrections(df53, "met_p4_jetcorrected", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metRecoilResponseDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, true, false, true, false);
    auto df55 = met::applyRecoilCorrections(df54, "met_p4_jetcorrected__metUnclusteredEnUp", "recoil_genboson_p4_vec", "Jet_pt_corrected", "met_p4_recoilcorrected__metUnclusteredEnUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df56 = met::applyRecoilCorrections(df55, "met_p4_jetcorrected__jesUncBBEC1YearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1YearUp", "met_p4_recoilcorrected__jesUncBBEC1YearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df57 = met::applyRecoilCorrections(df56, "met_p4_jetcorrected__jesUncHEMIssueUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHEMIssueUp", "met_p4_recoilcorrected__jesUncHEMIssueUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df58 = met::applyRecoilCorrections(df57, "met_p4_jetcorrected__jesUncRelativeSampleYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncRelativeSampleYearDown", "met_p4_recoilcorrected__jesUncRelativeSampleYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df59 = met::applyRecoilCorrections(df58, "met_p4_jetcorrected__jesUncHFUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFUp", "met_p4_recoilcorrected__jesUncHFUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df60 = met::applyRecoilCorrections(df59, "met_p4_jetcorrected__jesUncFlavorQCDDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncFlavorQCDDown", "met_p4_recoilcorrected__jesUncFlavorQCDDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df61 = met::applyRecoilCorrections(df60, "met_p4_jetcorrected__jesUncHEMIssueDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHEMIssueDown", "met_p4_recoilcorrected__jesUncHEMIssueDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df62 = met::applyRecoilCorrections(df61, "met_p4_jetcorrected__jesUncAbsoluteUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteUp", "met_p4_recoilcorrected__jesUncAbsoluteUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df63 = met::applyRecoilCorrections(df62, "met_p4_jetcorrected__jesUncEC2YearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2YearUp", "met_p4_recoilcorrected__jesUncEC2YearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df64 = met::applyRecoilCorrections(df63, "met_p4_jetcorrected__jesUncEC2Up", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncEC2Up", "met_p4_recoilcorrected__jesUncEC2Up", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df65 = met::applyRecoilCorrections(df64, "met_p4_jetcorrected__jesUncBBEC1Up", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1Up", "met_p4_recoilcorrected__jesUncBBEC1Up", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df66 = met::applyRecoilCorrections(df65, "met_p4_jetcorrected__jesUncAbsoluteYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncAbsoluteYearUp", "met_p4_recoilcorrected__jesUncAbsoluteYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df67 = met::applyRecoilCorrections(df66, "met_p4_jetcorrected__jesUncHFYearUp", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFYearUp", "met_p4_recoilcorrected__jesUncHFYearUp", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df68 = met::applyRecoilCorrections(df67, "met_p4_jetcorrected__jesUncHFYearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncHFYearDown", "met_p4_recoilcorrected__jesUncHFYearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df69 = met::applyRecoilCorrections(df68, "met_p4_jetcorrected__jesUncBBEC1YearDown", "recoil_genboson_p4_vec", "Jet_pt_corrected__jesUncBBEC1YearDown", "met_p4_recoilcorrected__jesUncBBEC1YearDown", "data/recoil_corrections/Type1_PuppiMET_2018.root", "data/recoil_corrections/PuppiMETSys_2018.root", false, false, false, false, false, false);
    auto df70 = quantities::pt(df69, "met", "met_p4_recoilcorrected");
    auto df71 = quantities::pt(df70, "met__metUnclusteredEnDown", "met_p4_recoilcorrected__metUnclusteredEnDown");
    auto df72 = quantities::pt(df71, "met__jesUncFlavorQCDUp", "met_p4_recoilcorrected__jesUncFlavorQCDUp");
    auto df73 = quantities::pt(df72, "met__jesUncHFDown", "met_p4_recoilcorrected__jesUncHFDown");
    auto df74 = quantities::pt(df73, "met__jesUncRelativeBalUp", "met_p4_recoilcorrected__jesUncRelativeBalUp");
    auto df75 = quantities::pt(df74, "met__jesUncTotalDown", "met_p4_recoilcorrected__jesUncTotalDown");
    auto df76 = quantities::pt(df75, "met__jesUncRelativeSampleYearUp", "met_p4_recoilcorrected__jesUncRelativeSampleYearUp");
    auto df77 = quantities::pt(df76, "met__jesUncAbsoluteDown", "met_p4_recoilcorrected__jesUncAbsoluteDown");
    auto df78 = quantities::pt(df77, "met__jerUncDown", "met_p4_recoilcorrected__jerUncDown");
    auto df79 = quantities::pt(df78, "met__jerUncUp", "met_p4_recoilcorrected__jerUncUp");
    auto df80 = quantities::pt(df79, "met__jesUncEC2YearDown", "met_p4_recoilcorrected__jesUncEC2YearDown");
    auto df81 = quantities::pt(df80, "met__metRecoilResolutionUp", "met_p4_recoilcorrected__metRecoilResolutionUp");
    auto df82 = quantities::pt(df81, "met__jesUncBBEC1Down", "met_p4_recoilcorrected__jesUncBBEC1Down");
    auto df83 = quantities::pt(df82, "met__jesUncEC2Down", "met_p4_recoilcorrected__jesUncEC2Down");
    auto df84 = quantities::pt(df83, "met__jesUncAbsoluteYearDown", "met_p4_recoilcorrected__jesUncAbsoluteYearDown");
    auto df85 = quantities::pt(df84, "met__jesUncRelativeBalDown", "met_p4_recoilcorrected__jesUncRelativeBalDown");
    auto df86 = quantities::pt(df85, "met__jesUncTotalUp", "met_p4_recoilcorrected__jesUncTotalUp");
    auto df87 = quantities::pt(df86, "met__metRecoilResponseUp", "met_p4_recoilcorrected__metRecoilResponseUp");
    auto df88 = quantities::pt(df87, "met__metRecoilResolutionDown", "met_p4_recoilcorrected__metRecoilResolutionDown");
    auto df89 = quantities::pt(df88, "met__metRecoilResponseDown", "met_p4_recoilcorrected__metRecoilResponseDown");
    auto df90 = quantities::pt(df89, "met__metUnclusteredEnUp", "met_p4_recoilcorrected__metUnclusteredEnUp");
    auto df91 = quantities::pt(df90, "met__jesUncBBEC1YearUp", "met_p4_recoilcorrected__jesUncBBEC1YearUp");
    auto df92 = quantities::pt(df91, "met__jesUncHEMIssueUp", "met_p4_recoilcorrected__jesUncHEMIssueUp");
    auto df93 = quantities::pt(df92, "met__jesUncRelativeSampleYearDown", "met_p4_recoilcorrected__jesUncRelativeSampleYearDown");
    auto df94 = quantities::pt(df93, "met__jesUncHFUp", "met_p4_recoilcorrected__jesUncHFUp");
    auto df95 = quantities::pt(df94, "met__jesUncFlavorQCDDown", "met_p4_recoilcorrected__jesUncFlavorQCDDown");
    auto df96 = quantities::pt(df95, "met__jesUncHEMIssueDown", "met_p4_recoilcorrected__jesUncHEMIssueDown");
    auto df97 = quantities::pt(df96, "met__jesUncAbsoluteUp", "met_p4_recoilcorrected__jesUncAbsoluteUp");
    auto df98 = quantities::pt(df97, "met__jesUncEC2YearUp", "met_p4_recoilcorrected__jesUncEC2YearUp");
    auto df99 = quantities::pt(df98, "met__jesUncEC2Up", "met_p4_recoilcorrected__jesUncEC2Up");
    auto df100 = quantities::pt(df99, "met__jesUncBBEC1Up", "met_p4_recoilcorrected__jesUncBBEC1Up");
    auto df101 = quantities::pt(df100, "met__jesUncAbsoluteYearUp", "met_p4_recoilcorrected__jesUncAbsoluteYearUp");
    auto df102 = quantities::pt(df101, "met__jesUncHFYearUp", "met_p4_recoilcorrected__jesUncHFYearUp");
    auto df103 = quantities::pt(df102, "met__jesUncHFYearDown", "met_p4_recoilcorrected__jesUncHFYearDown");
    auto df104 = quantities::pt(df103, "met__jesUncBBEC1YearDown", "met_p4_recoilcorrected__jesUncBBEC1YearDown");
    auto df105 = quantities::phi(df104, "metphi", "met_p4_recoilcorrected");
    auto df106 = quantities::phi(df105, "metphi__metUnclusteredEnDown", "met_p4_recoilcorrected__metUnclusteredEnDown");
    auto df107 = quantities::phi(df106, "metphi__jesUncFlavorQCDUp", "met_p4_recoilcorrected__jesUncFlavorQCDUp");
    auto df108 = quantities::phi(df107, "metphi__jesUncHFDown", "met_p4_recoilcorrected__jesUncHFDown");
    auto df109 = quantities::phi(df108, "metphi__jesUncRelativeBalUp", "met_p4_recoilcorrected__jesUncRelativeBalUp");
    auto df110 = quantities::phi(df109, "metphi__jesUncTotalDown", "met_p4_recoilcorrected__jesUncTotalDown");
    auto df111 = quantities::phi(df110, "metphi__jesUncRelativeSampleYearUp", "met_p4_recoilcorrected__jesUncRelativeSampleYearUp");
    auto df112 = quantities::phi(df111, "metphi__jesUncAbsoluteDown", "met_p4_recoilcorrected__jesUncAbsoluteDown");
    auto df113 = quantities::phi(df112, "metphi__jerUncDown", "met_p4_recoilcorrected__jerUncDown");
    auto df114 = quantities::phi(df113, "metphi__jerUncUp", "met_p4_recoilcorrected__jerUncUp");
    auto df115 = quantities::phi(df114, "metphi__jesUncEC2YearDown", "met_p4_recoilcorrected__jesUncEC2YearDown");
    auto df116 = quantities::phi(df115, "metphi__metRecoilResolutionUp", "met_p4_recoilcorrected__metRecoilResolutionUp");
    auto df117 = quantities::phi(df116, "metphi__jesUncBBEC1Down", "met_p4_recoilcorrected__jesUncBBEC1Down");
    auto df118 = quantities::phi(df117, "metphi__jesUncEC2Down", "met_p4_recoilcorrected__jesUncEC2Down");
    auto df119 = quantities::phi(df118, "metphi__jesUncAbsoluteYearDown", "met_p4_recoilcorrected__jesUncAbsoluteYearDown");
    auto df120 = quantities::phi(df119, "metphi__jesUncRelativeBalDown", "met_p4_recoilcorrected__jesUncRelativeBalDown");
    auto df121 = quantities::phi(df120, "metphi__jesUncTotalUp", "met_p4_recoilcorrected__jesUncTotalUp");
    auto df122 = quantities::phi(df121, "metphi__metRecoilResponseUp", "met_p4_recoilcorrected__metRecoilResponseUp");
    auto df123 = quantities::phi(df122, "metphi__metRecoilResolutionDown", "met_p4_recoilcorrected__metRecoilResolutionDown");
    auto df124 = quantities::phi(df123, "metphi__metRecoilResponseDown", "met_p4_recoilcorrected__metRecoilResponseDown");
    auto df125 = quantities::phi(df124, "metphi__metUnclusteredEnUp", "met_p4_recoilcorrected__metUnclusteredEnUp");
    auto df126 = quantities::phi(df125, "metphi__jesUncBBEC1YearUp", "met_p4_recoilcorrected__jesUncBBEC1YearUp");
    auto df127 = quantities::phi(df126, "metphi__jesUncHEMIssueUp", "met_p4_recoilcorrected__jesUncHEMIssueUp");
    auto df128 = quantities::phi(df127, "metphi__jesUncRelativeSampleYearDown", "met_p4_recoilcorrected__jesUncRelativeSampleYearDown");
    auto df129 = quantities::phi(df128, "metphi__jesUncHFUp", "met_p4_recoilcorrected__jesUncHFUp");
    auto df130 = quantities::phi(df129, "metphi__jesUncFlavorQCDDown", "met_p4_recoilcorrected__jesUncFlavorQCDDown");
    auto df131 = quantities::phi(df130, "metphi__jesUncHEMIssueDown", "met_p4_recoilcorrected__jesUncHEMIssueDown");
    auto df132 = quantities::phi(df131, "metphi__jesUncAbsoluteUp", "met_p4_recoilcorrected__jesUncAbsoluteUp");
    auto df133 = quantities::phi(df132, "metphi__jesUncEC2YearUp", "met_p4_recoilcorrected__jesUncEC2YearUp");
    auto df134 = quantities::phi(df133, "metphi__jesUncEC2Up", "met_p4_recoilcorrected__jesUncEC2Up");
    auto df135 = quantities::phi(df134, "metphi__jesUncBBEC1Up", "met_p4_recoilcorrected__jesUncBBEC1Up");
    auto df136 = quantities::phi(df135, "metphi__jesUncAbsoluteYearUp", "met_p4_recoilcorrected__jesUncAbsoluteYearUp");
    auto df137 = quantities::phi(df136, "metphi__jesUncHFYearUp", "met_p4_recoilcorrected__jesUncHFYearUp");
    auto df138 = quantities::phi(df137, "metphi__jesUncHFYearDown", "met_p4_recoilcorrected__jesUncHFYearDown");
    auto df139 = quantities::phi(df138, "metphi__jesUncBBEC1YearDown", "met_p4_recoilcorrected__jesUncBBEC1YearDown");
    return df139;

}
