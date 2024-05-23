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
ROOT::RDF::RNode JetEnergyCorrection_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::jet::JetPtCorrection(df0, correctionManager, "Jet_pt_corrected", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {""}, 0, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df2 = physicsobject::jet::JetPtCorrection(df1, correctionManager, "Jet_pt_corrected__jesUncFlavorQCDUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"FlavorQCD"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df3 = physicsobject::jet::JetPtCorrection(df2, correctionManager, "Jet_pt_corrected__jesUncHFDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativePtHF", "PileUpPtHF", "RelativeJERHF"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df4 = physicsobject::jet::JetPtCorrection(df3, correctionManager, "Jet_pt_corrected__jesUncRelativeBalUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeBal"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df5 = physicsobject::jet::JetPtCorrection(df4, correctionManager, "Jet_pt_corrected__jesUncTotalDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"Total"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df6 = physicsobject::jet::JetPtCorrection(df5, correctionManager, "Jet_pt_corrected__jesUncRelativeSampleYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeSample"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df7 = physicsobject::jet::JetPtCorrection(df6, correctionManager, "Jet_pt_corrected__jesUncAbsoluteDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"SinglePionECAL", "SinglePionHCAL", "AbsoluteMPFBias", "AbsoluteScale", "Fragmentation", "PileUpDataMC", "RelativeFSR", "PileUpPtRef"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df8 = physicsobject::jet::JetPtCorrection(df7, correctionManager, "Jet_pt_corrected__jerUncDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {""}, 0, "down", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df9 = physicsobject::jet::JetPtCorrection(df8, correctionManager, "Jet_pt_corrected__jerUncUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {""}, 0, "up", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df10 = physicsobject::jet::JetPtCorrection(df9, correctionManager, "Jet_pt_corrected__jesUncEC2YearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeJEREC2", "RelativePtEC2"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df11 = physicsobject::jet::JetPtCorrection(df10, correctionManager, "Jet_pt_corrected__jesUncBBEC1Down", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"PileUpPtEC1", "PileUpPtBB", "RelativePtBB"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df12 = physicsobject::jet::JetPtCorrection(df11, correctionManager, "Jet_pt_corrected__jesUncEC2Down", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"PileUpPtEC2"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df13 = physicsobject::jet::JetPtCorrection(df12, correctionManager, "Jet_pt_corrected__jesUncAbsoluteYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"AbsoluteStat", "TimePtEta", "RelativeStatFSR"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df14 = physicsobject::jet::JetPtCorrection(df13, correctionManager, "Jet_pt_corrected__jesUncRelativeBalDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeBal"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df15 = physicsobject::jet::JetPtCorrection(df14, correctionManager, "Jet_pt_corrected__jesUncTotalUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"Total"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df16 = physicsobject::jet::JetPtCorrection(df15, correctionManager, "Jet_pt_corrected__jesUncBBEC1YearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeJEREC1", "RelativePtEC1", "RelativeStatEC"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df17 = physicsobject::jet::JetPtCorrection(df16, correctionManager, "Jet_pt_corrected__jesUncHEMIssueUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"HEMIssue"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df18 = physicsobject::jet::JetPtCorrection(df17, correctionManager, "Jet_pt_corrected__jesUncRelativeSampleYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeSample"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df19 = physicsobject::jet::JetPtCorrection(df18, correctionManager, "Jet_pt_corrected__jesUncHFUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativePtHF", "PileUpPtHF", "RelativeJERHF"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df20 = physicsobject::jet::JetPtCorrection(df19, correctionManager, "Jet_pt_corrected__jesUncFlavorQCDDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"FlavorQCD"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df21 = physicsobject::jet::JetPtCorrection(df20, correctionManager, "Jet_pt_corrected__jesUncHEMIssueDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"HEMIssue"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df22 = physicsobject::jet::JetPtCorrection(df21, correctionManager, "Jet_pt_corrected__jesUncAbsoluteUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"SinglePionECAL", "SinglePionHCAL", "AbsoluteMPFBias", "AbsoluteScale", "Fragmentation", "PileUpDataMC", "RelativeFSR", "PileUpPtRef"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df23 = physicsobject::jet::JetPtCorrection(df22, correctionManager, "Jet_pt_corrected__jesUncEC2YearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeJEREC2", "RelativePtEC2"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df24 = physicsobject::jet::JetPtCorrection(df23, correctionManager, "Jet_pt_corrected__jesUncEC2Up", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"PileUpPtEC2"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df25 = physicsobject::jet::JetPtCorrection(df24, correctionManager, "Jet_pt_corrected__jesUncBBEC1Up", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"PileUpPtEC1", "PileUpPtBB", "RelativePtBB"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df26 = physicsobject::jet::JetPtCorrection(df25, correctionManager, "Jet_pt_corrected__jesUncAbsoluteYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"AbsoluteStat", "TimePtEta", "RelativeStatFSR"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df27 = physicsobject::jet::JetPtCorrection(df26, correctionManager, "Jet_pt_corrected__jesUncHFYearUp", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeStatHF"}, 1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df28 = physicsobject::jet::JetPtCorrection(df27, correctionManager, "Jet_pt_corrected__jesUncHFYearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeStatHF"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df29 = physicsobject::jet::JetPtCorrection(df28, correctionManager, "Jet_pt_corrected__jesUncBBEC1YearDown", "Jet_pt", "Jet_eta", "Jet_phi", "Jet_area", "Jet_rawFactor", "Jet_jetId", "GenJet_pt", "GenJet_eta", "GenJet_phi", "fixedGridRhoFastjetAll", false, {"RelativeJEREC1", "RelativePtEC1", "RelativeStatEC"}, -1, "nom", "data/jsonpog-integration/POG/JME/2018_UL/jet_jerc.json.gz", "Summer19UL18_JRV2_MC", "Summer19UL18_V5_MC", "AK4PFchs");
    auto df30 = physicsobject::ObjectMassCorrectionWithPt(df29, "Jet_mass_corrected", "Jet_mass", "Jet_pt", "Jet_pt_corrected");
    auto df31 = physicsobject::ObjectMassCorrectionWithPt(df30, "Jet_mass_corrected__jesUncFlavorQCDUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncFlavorQCDUp");
    auto df32 = physicsobject::ObjectMassCorrectionWithPt(df31, "Jet_mass_corrected__jesUncHFDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncHFDown");
    auto df33 = physicsobject::ObjectMassCorrectionWithPt(df32, "Jet_mass_corrected__jesUncRelativeBalUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncRelativeBalUp");
    auto df34 = physicsobject::ObjectMassCorrectionWithPt(df33, "Jet_mass_corrected__jesUncTotalDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncTotalDown");
    auto df35 = physicsobject::ObjectMassCorrectionWithPt(df34, "Jet_mass_corrected__jesUncRelativeSampleYearUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncRelativeSampleYearUp");
    auto df36 = physicsobject::ObjectMassCorrectionWithPt(df35, "Jet_mass_corrected__jesUncAbsoluteDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncAbsoluteDown");
    auto df37 = physicsobject::ObjectMassCorrectionWithPt(df36, "Jet_mass_corrected__jerUncDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jerUncDown");
    auto df38 = physicsobject::ObjectMassCorrectionWithPt(df37, "Jet_mass_corrected__jerUncUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jerUncUp");
    auto df39 = physicsobject::ObjectMassCorrectionWithPt(df38, "Jet_mass_corrected__jesUncEC2YearDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncEC2YearDown");
    auto df40 = physicsobject::ObjectMassCorrectionWithPt(df39, "Jet_mass_corrected__jesUncBBEC1Down", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncBBEC1Down");
    auto df41 = physicsobject::ObjectMassCorrectionWithPt(df40, "Jet_mass_corrected__jesUncEC2Down", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncEC2Down");
    auto df42 = physicsobject::ObjectMassCorrectionWithPt(df41, "Jet_mass_corrected__jesUncAbsoluteYearDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncAbsoluteYearDown");
    auto df43 = physicsobject::ObjectMassCorrectionWithPt(df42, "Jet_mass_corrected__jesUncRelativeBalDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncRelativeBalDown");
    auto df44 = physicsobject::ObjectMassCorrectionWithPt(df43, "Jet_mass_corrected__jesUncTotalUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncTotalUp");
    auto df45 = physicsobject::ObjectMassCorrectionWithPt(df44, "Jet_mass_corrected__jesUncBBEC1YearUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncBBEC1YearUp");
    auto df46 = physicsobject::ObjectMassCorrectionWithPt(df45, "Jet_mass_corrected__jesUncHEMIssueUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncHEMIssueUp");
    auto df47 = physicsobject::ObjectMassCorrectionWithPt(df46, "Jet_mass_corrected__jesUncRelativeSampleYearDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncRelativeSampleYearDown");
    auto df48 = physicsobject::ObjectMassCorrectionWithPt(df47, "Jet_mass_corrected__jesUncHFUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncHFUp");
    auto df49 = physicsobject::ObjectMassCorrectionWithPt(df48, "Jet_mass_corrected__jesUncFlavorQCDDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncFlavorQCDDown");
    auto df50 = physicsobject::ObjectMassCorrectionWithPt(df49, "Jet_mass_corrected__jesUncHEMIssueDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncHEMIssueDown");
    auto df51 = physicsobject::ObjectMassCorrectionWithPt(df50, "Jet_mass_corrected__jesUncAbsoluteUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncAbsoluteUp");
    auto df52 = physicsobject::ObjectMassCorrectionWithPt(df51, "Jet_mass_corrected__jesUncEC2YearUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncEC2YearUp");
    auto df53 = physicsobject::ObjectMassCorrectionWithPt(df52, "Jet_mass_corrected__jesUncEC2Up", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncEC2Up");
    auto df54 = physicsobject::ObjectMassCorrectionWithPt(df53, "Jet_mass_corrected__jesUncBBEC1Up", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncBBEC1Up");
    auto df55 = physicsobject::ObjectMassCorrectionWithPt(df54, "Jet_mass_corrected__jesUncAbsoluteYearUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncAbsoluteYearUp");
    auto df56 = physicsobject::ObjectMassCorrectionWithPt(df55, "Jet_mass_corrected__jesUncHFYearUp", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncHFYearUp");
    auto df57 = physicsobject::ObjectMassCorrectionWithPt(df56, "Jet_mass_corrected__jesUncHFYearDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncHFYearDown");
    auto df58 = physicsobject::ObjectMassCorrectionWithPt(df57, "Jet_mass_corrected__jesUncBBEC1YearDown", "Jet_mass", "Jet_pt", "Jet_pt_corrected__jesUncBBEC1YearDown");
    return df58;

}
