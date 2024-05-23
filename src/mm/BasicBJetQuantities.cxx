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
ROOT::RDF::RNode BasicBJetQuantities_mm (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = lorentzvectors::build(df0, {"good_bjet_collection","Jet_pt_corrected","Jet_eta","Jet_phi","Jet_mass_corrected"}, 0, "bjet_p4_1");
    auto df2 = lorentzvectors::build(df1, {"good_bjet_collection__jesUncFlavorQCDUp","Jet_pt_corrected__jesUncFlavorQCDUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncFlavorQCDUp"}, 0, "bjet_p4_1__jesUncFlavorQCDUp");
    auto df3 = lorentzvectors::build(df2, {"good_bjet_collection__jesUncHFDown","Jet_pt_corrected__jesUncHFDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHFDown"}, 0, "bjet_p4_1__jesUncHFDown");
    auto df4 = lorentzvectors::build(df3, {"good_bjet_collection__jesUncRelativeBalUp","Jet_pt_corrected__jesUncRelativeBalUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncRelativeBalUp"}, 0, "bjet_p4_1__jesUncRelativeBalUp");
    auto df5 = lorentzvectors::build(df4, {"good_bjet_collection__jesUncTotalDown","Jet_pt_corrected__jesUncTotalDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncTotalDown"}, 0, "bjet_p4_1__jesUncTotalDown");
    auto df6 = lorentzvectors::build(df5, {"good_bjet_collection__jesUncRelativeSampleYearUp","Jet_pt_corrected__jesUncRelativeSampleYearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncRelativeSampleYearUp"}, 0, "bjet_p4_1__jesUncRelativeSampleYearUp");
    auto df7 = lorentzvectors::build(df6, {"good_bjet_collection__jesUncAbsoluteDown","Jet_pt_corrected__jesUncAbsoluteDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncAbsoluteDown"}, 0, "bjet_p4_1__jesUncAbsoluteDown");
    auto df8 = lorentzvectors::build(df7, {"good_bjet_collection__jerUncDown","Jet_pt_corrected__jerUncDown","Jet_eta","Jet_phi","Jet_mass_corrected__jerUncDown"}, 0, "bjet_p4_1__jerUncDown");
    auto df9 = lorentzvectors::build(df8, {"good_bjet_collection__jerUncUp","Jet_pt_corrected__jerUncUp","Jet_eta","Jet_phi","Jet_mass_corrected__jerUncUp"}, 0, "bjet_p4_1__jerUncUp");
    auto df10 = lorentzvectors::build(df9, {"good_bjet_collection__jesUncEC2YearDown","Jet_pt_corrected__jesUncEC2YearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncEC2YearDown"}, 0, "bjet_p4_1__jesUncEC2YearDown");
    auto df11 = lorentzvectors::build(df10, {"good_bjet_collection__jesUncBBEC1Down","Jet_pt_corrected__jesUncBBEC1Down","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncBBEC1Down"}, 0, "bjet_p4_1__jesUncBBEC1Down");
    auto df12 = lorentzvectors::build(df11, {"good_bjet_collection__jesUncEC2Down","Jet_pt_corrected__jesUncEC2Down","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncEC2Down"}, 0, "bjet_p4_1__jesUncEC2Down");
    auto df13 = lorentzvectors::build(df12, {"good_bjet_collection__jesUncAbsoluteYearDown","Jet_pt_corrected__jesUncAbsoluteYearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncAbsoluteYearDown"}, 0, "bjet_p4_1__jesUncAbsoluteYearDown");
    auto df14 = lorentzvectors::build(df13, {"good_bjet_collection__jesUncRelativeBalDown","Jet_pt_corrected__jesUncRelativeBalDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncRelativeBalDown"}, 0, "bjet_p4_1__jesUncRelativeBalDown");
    auto df15 = lorentzvectors::build(df14, {"good_bjet_collection__jesUncTotalUp","Jet_pt_corrected__jesUncTotalUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncTotalUp"}, 0, "bjet_p4_1__jesUncTotalUp");
    auto df16 = lorentzvectors::build(df15, {"good_bjet_collection__jesUncBBEC1YearUp","Jet_pt_corrected__jesUncBBEC1YearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncBBEC1YearUp"}, 0, "bjet_p4_1__jesUncBBEC1YearUp");
    auto df17 = lorentzvectors::build(df16, {"good_bjet_collection__jesUncHEMIssueUp","Jet_pt_corrected__jesUncHEMIssueUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHEMIssueUp"}, 0, "bjet_p4_1__jesUncHEMIssueUp");
    auto df18 = lorentzvectors::build(df17, {"good_bjet_collection__jesUncRelativeSampleYearDown","Jet_pt_corrected__jesUncRelativeSampleYearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncRelativeSampleYearDown"}, 0, "bjet_p4_1__jesUncRelativeSampleYearDown");
    auto df19 = lorentzvectors::build(df18, {"good_bjet_collection__jesUncHFUp","Jet_pt_corrected__jesUncHFUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHFUp"}, 0, "bjet_p4_1__jesUncHFUp");
    auto df20 = lorentzvectors::build(df19, {"good_bjet_collection__jesUncFlavorQCDDown","Jet_pt_corrected__jesUncFlavorQCDDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncFlavorQCDDown"}, 0, "bjet_p4_1__jesUncFlavorQCDDown");
    auto df21 = lorentzvectors::build(df20, {"good_bjet_collection__jesUncHEMIssueDown","Jet_pt_corrected__jesUncHEMIssueDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHEMIssueDown"}, 0, "bjet_p4_1__jesUncHEMIssueDown");
    auto df22 = lorentzvectors::build(df21, {"good_bjet_collection__jesUncAbsoluteUp","Jet_pt_corrected__jesUncAbsoluteUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncAbsoluteUp"}, 0, "bjet_p4_1__jesUncAbsoluteUp");
    auto df23 = lorentzvectors::build(df22, {"good_bjet_collection__jesUncEC2YearUp","Jet_pt_corrected__jesUncEC2YearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncEC2YearUp"}, 0, "bjet_p4_1__jesUncEC2YearUp");
    auto df24 = lorentzvectors::build(df23, {"good_bjet_collection__jesUncEC2Up","Jet_pt_corrected__jesUncEC2Up","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncEC2Up"}, 0, "bjet_p4_1__jesUncEC2Up");
    auto df25 = lorentzvectors::build(df24, {"good_bjet_collection__jesUncBBEC1Up","Jet_pt_corrected__jesUncBBEC1Up","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncBBEC1Up"}, 0, "bjet_p4_1__jesUncBBEC1Up");
    auto df26 = lorentzvectors::build(df25, {"good_bjet_collection__jesUncAbsoluteYearUp","Jet_pt_corrected__jesUncAbsoluteYearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncAbsoluteYearUp"}, 0, "bjet_p4_1__jesUncAbsoluteYearUp");
    auto df27 = lorentzvectors::build(df26, {"good_bjet_collection__jesUncHFYearUp","Jet_pt_corrected__jesUncHFYearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHFYearUp"}, 0, "bjet_p4_1__jesUncHFYearUp");
    auto df28 = lorentzvectors::build(df27, {"good_bjet_collection__jesUncHFYearDown","Jet_pt_corrected__jesUncHFYearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHFYearDown"}, 0, "bjet_p4_1__jesUncHFYearDown");
    auto df29 = lorentzvectors::build(df28, {"good_bjet_collection__jesUncBBEC1YearDown","Jet_pt_corrected__jesUncBBEC1YearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncBBEC1YearDown"}, 0, "bjet_p4_1__jesUncBBEC1YearDown");
    auto df30 = lorentzvectors::build(df29, {"good_bjet_collection","Jet_pt_corrected","Jet_eta","Jet_phi","Jet_mass_corrected"}, 1, "bjet_p4_2");
    auto df31 = lorentzvectors::build(df30, {"good_bjet_collection__jesUncFlavorQCDUp","Jet_pt_corrected__jesUncFlavorQCDUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncFlavorQCDUp"}, 1, "bjet_p4_2__jesUncFlavorQCDUp");
    auto df32 = lorentzvectors::build(df31, {"good_bjet_collection__jesUncHFDown","Jet_pt_corrected__jesUncHFDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHFDown"}, 1, "bjet_p4_2__jesUncHFDown");
    auto df33 = lorentzvectors::build(df32, {"good_bjet_collection__jesUncRelativeBalUp","Jet_pt_corrected__jesUncRelativeBalUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncRelativeBalUp"}, 1, "bjet_p4_2__jesUncRelativeBalUp");
    auto df34 = lorentzvectors::build(df33, {"good_bjet_collection__jesUncTotalDown","Jet_pt_corrected__jesUncTotalDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncTotalDown"}, 1, "bjet_p4_2__jesUncTotalDown");
    auto df35 = lorentzvectors::build(df34, {"good_bjet_collection__jesUncRelativeSampleYearUp","Jet_pt_corrected__jesUncRelativeSampleYearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncRelativeSampleYearUp"}, 1, "bjet_p4_2__jesUncRelativeSampleYearUp");
    auto df36 = lorentzvectors::build(df35, {"good_bjet_collection__jesUncAbsoluteDown","Jet_pt_corrected__jesUncAbsoluteDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncAbsoluteDown"}, 1, "bjet_p4_2__jesUncAbsoluteDown");
    auto df37 = lorentzvectors::build(df36, {"good_bjet_collection__jerUncDown","Jet_pt_corrected__jerUncDown","Jet_eta","Jet_phi","Jet_mass_corrected__jerUncDown"}, 1, "bjet_p4_2__jerUncDown");
    auto df38 = lorentzvectors::build(df37, {"good_bjet_collection__jerUncUp","Jet_pt_corrected__jerUncUp","Jet_eta","Jet_phi","Jet_mass_corrected__jerUncUp"}, 1, "bjet_p4_2__jerUncUp");
    auto df39 = lorentzvectors::build(df38, {"good_bjet_collection__jesUncEC2YearDown","Jet_pt_corrected__jesUncEC2YearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncEC2YearDown"}, 1, "bjet_p4_2__jesUncEC2YearDown");
    auto df40 = lorentzvectors::build(df39, {"good_bjet_collection__jesUncBBEC1Down","Jet_pt_corrected__jesUncBBEC1Down","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncBBEC1Down"}, 1, "bjet_p4_2__jesUncBBEC1Down");
    auto df41 = lorentzvectors::build(df40, {"good_bjet_collection__jesUncEC2Down","Jet_pt_corrected__jesUncEC2Down","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncEC2Down"}, 1, "bjet_p4_2__jesUncEC2Down");
    auto df42 = lorentzvectors::build(df41, {"good_bjet_collection__jesUncAbsoluteYearDown","Jet_pt_corrected__jesUncAbsoluteYearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncAbsoluteYearDown"}, 1, "bjet_p4_2__jesUncAbsoluteYearDown");
    auto df43 = lorentzvectors::build(df42, {"good_bjet_collection__jesUncRelativeBalDown","Jet_pt_corrected__jesUncRelativeBalDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncRelativeBalDown"}, 1, "bjet_p4_2__jesUncRelativeBalDown");
    auto df44 = lorentzvectors::build(df43, {"good_bjet_collection__jesUncTotalUp","Jet_pt_corrected__jesUncTotalUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncTotalUp"}, 1, "bjet_p4_2__jesUncTotalUp");
    auto df45 = lorentzvectors::build(df44, {"good_bjet_collection__jesUncBBEC1YearUp","Jet_pt_corrected__jesUncBBEC1YearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncBBEC1YearUp"}, 1, "bjet_p4_2__jesUncBBEC1YearUp");
    auto df46 = lorentzvectors::build(df45, {"good_bjet_collection__jesUncHEMIssueUp","Jet_pt_corrected__jesUncHEMIssueUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHEMIssueUp"}, 1, "bjet_p4_2__jesUncHEMIssueUp");
    auto df47 = lorentzvectors::build(df46, {"good_bjet_collection__jesUncRelativeSampleYearDown","Jet_pt_corrected__jesUncRelativeSampleYearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncRelativeSampleYearDown"}, 1, "bjet_p4_2__jesUncRelativeSampleYearDown");
    auto df48 = lorentzvectors::build(df47, {"good_bjet_collection__jesUncHFUp","Jet_pt_corrected__jesUncHFUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHFUp"}, 1, "bjet_p4_2__jesUncHFUp");
    auto df49 = lorentzvectors::build(df48, {"good_bjet_collection__jesUncFlavorQCDDown","Jet_pt_corrected__jesUncFlavorQCDDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncFlavorQCDDown"}, 1, "bjet_p4_2__jesUncFlavorQCDDown");
    auto df50 = lorentzvectors::build(df49, {"good_bjet_collection__jesUncHEMIssueDown","Jet_pt_corrected__jesUncHEMIssueDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHEMIssueDown"}, 1, "bjet_p4_2__jesUncHEMIssueDown");
    auto df51 = lorentzvectors::build(df50, {"good_bjet_collection__jesUncAbsoluteUp","Jet_pt_corrected__jesUncAbsoluteUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncAbsoluteUp"}, 1, "bjet_p4_2__jesUncAbsoluteUp");
    auto df52 = lorentzvectors::build(df51, {"good_bjet_collection__jesUncEC2YearUp","Jet_pt_corrected__jesUncEC2YearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncEC2YearUp"}, 1, "bjet_p4_2__jesUncEC2YearUp");
    auto df53 = lorentzvectors::build(df52, {"good_bjet_collection__jesUncEC2Up","Jet_pt_corrected__jesUncEC2Up","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncEC2Up"}, 1, "bjet_p4_2__jesUncEC2Up");
    auto df54 = lorentzvectors::build(df53, {"good_bjet_collection__jesUncBBEC1Up","Jet_pt_corrected__jesUncBBEC1Up","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncBBEC1Up"}, 1, "bjet_p4_2__jesUncBBEC1Up");
    auto df55 = lorentzvectors::build(df54, {"good_bjet_collection__jesUncAbsoluteYearUp","Jet_pt_corrected__jesUncAbsoluteYearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncAbsoluteYearUp"}, 1, "bjet_p4_2__jesUncAbsoluteYearUp");
    auto df56 = lorentzvectors::build(df55, {"good_bjet_collection__jesUncHFYearUp","Jet_pt_corrected__jesUncHFYearUp","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHFYearUp"}, 1, "bjet_p4_2__jesUncHFYearUp");
    auto df57 = lorentzvectors::build(df56, {"good_bjet_collection__jesUncHFYearDown","Jet_pt_corrected__jesUncHFYearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncHFYearDown"}, 1, "bjet_p4_2__jesUncHFYearDown");
    auto df58 = lorentzvectors::build(df57, {"good_bjet_collection__jesUncBBEC1YearDown","Jet_pt_corrected__jesUncBBEC1YearDown","Jet_eta","Jet_phi","Jet_mass_corrected__jesUncBBEC1YearDown"}, 1, "bjet_p4_2__jesUncBBEC1YearDown");
    auto df59 = quantities::jet::NumberOfJets(df58, "nbtag", "good_bjet_collection");
    auto df60 = quantities::jet::NumberOfJets(df59, "nbtag__jesUncFlavorQCDUp", "good_bjet_collection__jesUncFlavorQCDUp");
    auto df61 = quantities::jet::NumberOfJets(df60, "nbtag__jesUncHFDown", "good_bjet_collection__jesUncHFDown");
    auto df62 = quantities::jet::NumberOfJets(df61, "nbtag__jesUncRelativeBalUp", "good_bjet_collection__jesUncRelativeBalUp");
    auto df63 = quantities::jet::NumberOfJets(df62, "nbtag__jesUncTotalDown", "good_bjet_collection__jesUncTotalDown");
    auto df64 = quantities::jet::NumberOfJets(df63, "nbtag__jesUncRelativeSampleYearUp", "good_bjet_collection__jesUncRelativeSampleYearUp");
    auto df65 = quantities::jet::NumberOfJets(df64, "nbtag__jesUncAbsoluteDown", "good_bjet_collection__jesUncAbsoluteDown");
    auto df66 = quantities::jet::NumberOfJets(df65, "nbtag__jerUncDown", "good_bjet_collection__jerUncDown");
    auto df67 = quantities::jet::NumberOfJets(df66, "nbtag__jerUncUp", "good_bjet_collection__jerUncUp");
    auto df68 = quantities::jet::NumberOfJets(df67, "nbtag__jesUncEC2YearDown", "good_bjet_collection__jesUncEC2YearDown");
    auto df69 = quantities::jet::NumberOfJets(df68, "nbtag__jesUncBBEC1Down", "good_bjet_collection__jesUncBBEC1Down");
    auto df70 = quantities::jet::NumberOfJets(df69, "nbtag__jesUncEC2Down", "good_bjet_collection__jesUncEC2Down");
    auto df71 = quantities::jet::NumberOfJets(df70, "nbtag__jesUncAbsoluteYearDown", "good_bjet_collection__jesUncAbsoluteYearDown");
    auto df72 = quantities::jet::NumberOfJets(df71, "nbtag__jesUncRelativeBalDown", "good_bjet_collection__jesUncRelativeBalDown");
    auto df73 = quantities::jet::NumberOfJets(df72, "nbtag__jesUncTotalUp", "good_bjet_collection__jesUncTotalUp");
    auto df74 = quantities::jet::NumberOfJets(df73, "nbtag__jesUncBBEC1YearUp", "good_bjet_collection__jesUncBBEC1YearUp");
    auto df75 = quantities::jet::NumberOfJets(df74, "nbtag__jesUncHEMIssueUp", "good_bjet_collection__jesUncHEMIssueUp");
    auto df76 = quantities::jet::NumberOfJets(df75, "nbtag__jesUncRelativeSampleYearDown", "good_bjet_collection__jesUncRelativeSampleYearDown");
    auto df77 = quantities::jet::NumberOfJets(df76, "nbtag__jesUncHFUp", "good_bjet_collection__jesUncHFUp");
    auto df78 = quantities::jet::NumberOfJets(df77, "nbtag__jesUncFlavorQCDDown", "good_bjet_collection__jesUncFlavorQCDDown");
    auto df79 = quantities::jet::NumberOfJets(df78, "nbtag__jesUncHEMIssueDown", "good_bjet_collection__jesUncHEMIssueDown");
    auto df80 = quantities::jet::NumberOfJets(df79, "nbtag__jesUncAbsoluteUp", "good_bjet_collection__jesUncAbsoluteUp");
    auto df81 = quantities::jet::NumberOfJets(df80, "nbtag__jesUncEC2YearUp", "good_bjet_collection__jesUncEC2YearUp");
    auto df82 = quantities::jet::NumberOfJets(df81, "nbtag__jesUncEC2Up", "good_bjet_collection__jesUncEC2Up");
    auto df83 = quantities::jet::NumberOfJets(df82, "nbtag__jesUncBBEC1Up", "good_bjet_collection__jesUncBBEC1Up");
    auto df84 = quantities::jet::NumberOfJets(df83, "nbtag__jesUncAbsoluteYearUp", "good_bjet_collection__jesUncAbsoluteYearUp");
    auto df85 = quantities::jet::NumberOfJets(df84, "nbtag__jesUncHFYearUp", "good_bjet_collection__jesUncHFYearUp");
    auto df86 = quantities::jet::NumberOfJets(df85, "nbtag__jesUncHFYearDown", "good_bjet_collection__jesUncHFYearDown");
    auto df87 = quantities::jet::NumberOfJets(df86, "nbtag__jesUncBBEC1YearDown", "good_bjet_collection__jesUncBBEC1YearDown");
    auto df88 = quantities::pt(df87, "bpt_1", "bjet_p4_1");
    auto df89 = quantities::pt(df88, "bpt_1__jesUncFlavorQCDUp", "bjet_p4_1__jesUncFlavorQCDUp");
    auto df90 = quantities::pt(df89, "bpt_1__jesUncHFDown", "bjet_p4_1__jesUncHFDown");
    auto df91 = quantities::pt(df90, "bpt_1__jesUncRelativeBalUp", "bjet_p4_1__jesUncRelativeBalUp");
    auto df92 = quantities::pt(df91, "bpt_1__jesUncTotalDown", "bjet_p4_1__jesUncTotalDown");
    auto df93 = quantities::pt(df92, "bpt_1__jesUncRelativeSampleYearUp", "bjet_p4_1__jesUncRelativeSampleYearUp");
    auto df94 = quantities::pt(df93, "bpt_1__jesUncAbsoluteDown", "bjet_p4_1__jesUncAbsoluteDown");
    auto df95 = quantities::pt(df94, "bpt_1__jerUncDown", "bjet_p4_1__jerUncDown");
    auto df96 = quantities::pt(df95, "bpt_1__jerUncUp", "bjet_p4_1__jerUncUp");
    auto df97 = quantities::pt(df96, "bpt_1__jesUncEC2YearDown", "bjet_p4_1__jesUncEC2YearDown");
    auto df98 = quantities::pt(df97, "bpt_1__jesUncBBEC1Down", "bjet_p4_1__jesUncBBEC1Down");
    auto df99 = quantities::pt(df98, "bpt_1__jesUncEC2Down", "bjet_p4_1__jesUncEC2Down");
    auto df100 = quantities::pt(df99, "bpt_1__jesUncAbsoluteYearDown", "bjet_p4_1__jesUncAbsoluteYearDown");
    auto df101 = quantities::pt(df100, "bpt_1__jesUncRelativeBalDown", "bjet_p4_1__jesUncRelativeBalDown");
    auto df102 = quantities::pt(df101, "bpt_1__jesUncTotalUp", "bjet_p4_1__jesUncTotalUp");
    auto df103 = quantities::pt(df102, "bpt_1__jesUncBBEC1YearUp", "bjet_p4_1__jesUncBBEC1YearUp");
    auto df104 = quantities::pt(df103, "bpt_1__jesUncHEMIssueUp", "bjet_p4_1__jesUncHEMIssueUp");
    auto df105 = quantities::pt(df104, "bpt_1__jesUncRelativeSampleYearDown", "bjet_p4_1__jesUncRelativeSampleYearDown");
    auto df106 = quantities::pt(df105, "bpt_1__jesUncHFUp", "bjet_p4_1__jesUncHFUp");
    auto df107 = quantities::pt(df106, "bpt_1__jesUncFlavorQCDDown", "bjet_p4_1__jesUncFlavorQCDDown");
    auto df108 = quantities::pt(df107, "bpt_1__jesUncHEMIssueDown", "bjet_p4_1__jesUncHEMIssueDown");
    auto df109 = quantities::pt(df108, "bpt_1__jesUncAbsoluteUp", "bjet_p4_1__jesUncAbsoluteUp");
    auto df110 = quantities::pt(df109, "bpt_1__jesUncEC2YearUp", "bjet_p4_1__jesUncEC2YearUp");
    auto df111 = quantities::pt(df110, "bpt_1__jesUncEC2Up", "bjet_p4_1__jesUncEC2Up");
    auto df112 = quantities::pt(df111, "bpt_1__jesUncBBEC1Up", "bjet_p4_1__jesUncBBEC1Up");
    auto df113 = quantities::pt(df112, "bpt_1__jesUncAbsoluteYearUp", "bjet_p4_1__jesUncAbsoluteYearUp");
    auto df114 = quantities::pt(df113, "bpt_1__jesUncHFYearUp", "bjet_p4_1__jesUncHFYearUp");
    auto df115 = quantities::pt(df114, "bpt_1__jesUncHFYearDown", "bjet_p4_1__jesUncHFYearDown");
    auto df116 = quantities::pt(df115, "bpt_1__jesUncBBEC1YearDown", "bjet_p4_1__jesUncBBEC1YearDown");
    auto df117 = quantities::eta(df116, "beta_1", "bjet_p4_1");
    auto df118 = quantities::eta(df117, "beta_1__jesUncFlavorQCDUp", "bjet_p4_1__jesUncFlavorQCDUp");
    auto df119 = quantities::eta(df118, "beta_1__jesUncHFDown", "bjet_p4_1__jesUncHFDown");
    auto df120 = quantities::eta(df119, "beta_1__jesUncRelativeBalUp", "bjet_p4_1__jesUncRelativeBalUp");
    auto df121 = quantities::eta(df120, "beta_1__jesUncTotalDown", "bjet_p4_1__jesUncTotalDown");
    auto df122 = quantities::eta(df121, "beta_1__jesUncRelativeSampleYearUp", "bjet_p4_1__jesUncRelativeSampleYearUp");
    auto df123 = quantities::eta(df122, "beta_1__jesUncAbsoluteDown", "bjet_p4_1__jesUncAbsoluteDown");
    auto df124 = quantities::eta(df123, "beta_1__jerUncDown", "bjet_p4_1__jerUncDown");
    auto df125 = quantities::eta(df124, "beta_1__jerUncUp", "bjet_p4_1__jerUncUp");
    auto df126 = quantities::eta(df125, "beta_1__jesUncEC2YearDown", "bjet_p4_1__jesUncEC2YearDown");
    auto df127 = quantities::eta(df126, "beta_1__jesUncBBEC1Down", "bjet_p4_1__jesUncBBEC1Down");
    auto df128 = quantities::eta(df127, "beta_1__jesUncEC2Down", "bjet_p4_1__jesUncEC2Down");
    auto df129 = quantities::eta(df128, "beta_1__jesUncAbsoluteYearDown", "bjet_p4_1__jesUncAbsoluteYearDown");
    auto df130 = quantities::eta(df129, "beta_1__jesUncRelativeBalDown", "bjet_p4_1__jesUncRelativeBalDown");
    auto df131 = quantities::eta(df130, "beta_1__jesUncTotalUp", "bjet_p4_1__jesUncTotalUp");
    auto df132 = quantities::eta(df131, "beta_1__jesUncBBEC1YearUp", "bjet_p4_1__jesUncBBEC1YearUp");
    auto df133 = quantities::eta(df132, "beta_1__jesUncHEMIssueUp", "bjet_p4_1__jesUncHEMIssueUp");
    auto df134 = quantities::eta(df133, "beta_1__jesUncRelativeSampleYearDown", "bjet_p4_1__jesUncRelativeSampleYearDown");
    auto df135 = quantities::eta(df134, "beta_1__jesUncHFUp", "bjet_p4_1__jesUncHFUp");
    auto df136 = quantities::eta(df135, "beta_1__jesUncFlavorQCDDown", "bjet_p4_1__jesUncFlavorQCDDown");
    auto df137 = quantities::eta(df136, "beta_1__jesUncHEMIssueDown", "bjet_p4_1__jesUncHEMIssueDown");
    auto df138 = quantities::eta(df137, "beta_1__jesUncAbsoluteUp", "bjet_p4_1__jesUncAbsoluteUp");
    auto df139 = quantities::eta(df138, "beta_1__jesUncEC2YearUp", "bjet_p4_1__jesUncEC2YearUp");
    auto df140 = quantities::eta(df139, "beta_1__jesUncEC2Up", "bjet_p4_1__jesUncEC2Up");
    auto df141 = quantities::eta(df140, "beta_1__jesUncBBEC1Up", "bjet_p4_1__jesUncBBEC1Up");
    auto df142 = quantities::eta(df141, "beta_1__jesUncAbsoluteYearUp", "bjet_p4_1__jesUncAbsoluteYearUp");
    auto df143 = quantities::eta(df142, "beta_1__jesUncHFYearUp", "bjet_p4_1__jesUncHFYearUp");
    auto df144 = quantities::eta(df143, "beta_1__jesUncHFYearDown", "bjet_p4_1__jesUncHFYearDown");
    auto df145 = quantities::eta(df144, "beta_1__jesUncBBEC1YearDown", "bjet_p4_1__jesUncBBEC1YearDown");
    auto df146 = quantities::phi(df145, "bphi_1", "bjet_p4_1");
    auto df147 = quantities::phi(df146, "bphi_1__jesUncFlavorQCDUp", "bjet_p4_1__jesUncFlavorQCDUp");
    auto df148 = quantities::phi(df147, "bphi_1__jesUncHFDown", "bjet_p4_1__jesUncHFDown");
    auto df149 = quantities::phi(df148, "bphi_1__jesUncRelativeBalUp", "bjet_p4_1__jesUncRelativeBalUp");
    auto df150 = quantities::phi(df149, "bphi_1__jesUncTotalDown", "bjet_p4_1__jesUncTotalDown");
    auto df151 = quantities::phi(df150, "bphi_1__jesUncRelativeSampleYearUp", "bjet_p4_1__jesUncRelativeSampleYearUp");
    auto df152 = quantities::phi(df151, "bphi_1__jesUncAbsoluteDown", "bjet_p4_1__jesUncAbsoluteDown");
    auto df153 = quantities::phi(df152, "bphi_1__jerUncDown", "bjet_p4_1__jerUncDown");
    auto df154 = quantities::phi(df153, "bphi_1__jerUncUp", "bjet_p4_1__jerUncUp");
    auto df155 = quantities::phi(df154, "bphi_1__jesUncEC2YearDown", "bjet_p4_1__jesUncEC2YearDown");
    auto df156 = quantities::phi(df155, "bphi_1__jesUncBBEC1Down", "bjet_p4_1__jesUncBBEC1Down");
    auto df157 = quantities::phi(df156, "bphi_1__jesUncEC2Down", "bjet_p4_1__jesUncEC2Down");
    auto df158 = quantities::phi(df157, "bphi_1__jesUncAbsoluteYearDown", "bjet_p4_1__jesUncAbsoluteYearDown");
    auto df159 = quantities::phi(df158, "bphi_1__jesUncRelativeBalDown", "bjet_p4_1__jesUncRelativeBalDown");
    auto df160 = quantities::phi(df159, "bphi_1__jesUncTotalUp", "bjet_p4_1__jesUncTotalUp");
    auto df161 = quantities::phi(df160, "bphi_1__jesUncBBEC1YearUp", "bjet_p4_1__jesUncBBEC1YearUp");
    auto df162 = quantities::phi(df161, "bphi_1__jesUncHEMIssueUp", "bjet_p4_1__jesUncHEMIssueUp");
    auto df163 = quantities::phi(df162, "bphi_1__jesUncRelativeSampleYearDown", "bjet_p4_1__jesUncRelativeSampleYearDown");
    auto df164 = quantities::phi(df163, "bphi_1__jesUncHFUp", "bjet_p4_1__jesUncHFUp");
    auto df165 = quantities::phi(df164, "bphi_1__jesUncFlavorQCDDown", "bjet_p4_1__jesUncFlavorQCDDown");
    auto df166 = quantities::phi(df165, "bphi_1__jesUncHEMIssueDown", "bjet_p4_1__jesUncHEMIssueDown");
    auto df167 = quantities::phi(df166, "bphi_1__jesUncAbsoluteUp", "bjet_p4_1__jesUncAbsoluteUp");
    auto df168 = quantities::phi(df167, "bphi_1__jesUncEC2YearUp", "bjet_p4_1__jesUncEC2YearUp");
    auto df169 = quantities::phi(df168, "bphi_1__jesUncEC2Up", "bjet_p4_1__jesUncEC2Up");
    auto df170 = quantities::phi(df169, "bphi_1__jesUncBBEC1Up", "bjet_p4_1__jesUncBBEC1Up");
    auto df171 = quantities::phi(df170, "bphi_1__jesUncAbsoluteYearUp", "bjet_p4_1__jesUncAbsoluteYearUp");
    auto df172 = quantities::phi(df171, "bphi_1__jesUncHFYearUp", "bjet_p4_1__jesUncHFYearUp");
    auto df173 = quantities::phi(df172, "bphi_1__jesUncHFYearDown", "bjet_p4_1__jesUncHFYearDown");
    auto df174 = quantities::phi(df173, "bphi_1__jesUncBBEC1YearDown", "bjet_p4_1__jesUncBBEC1YearDown");
    auto df175 = quantities::jet::btagValue(df174, "btag_value_1", "Jet_btagDeepFlavB", "good_bjet_collection", 0);
    auto df176 = quantities::jet::btagValue(df175, "btag_value_1__jesUncFlavorQCDUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncFlavorQCDUp", 0);
    auto df177 = quantities::jet::btagValue(df176, "btag_value_1__jesUncHFDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHFDown", 0);
    auto df178 = quantities::jet::btagValue(df177, "btag_value_1__jesUncRelativeBalUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncRelativeBalUp", 0);
    auto df179 = quantities::jet::btagValue(df178, "btag_value_1__jesUncTotalDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncTotalDown", 0);
    auto df180 = quantities::jet::btagValue(df179, "btag_value_1__jesUncRelativeSampleYearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncRelativeSampleYearUp", 0);
    auto df181 = quantities::jet::btagValue(df180, "btag_value_1__jesUncAbsoluteDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncAbsoluteDown", 0);
    auto df182 = quantities::jet::btagValue(df181, "btag_value_1__jerUncDown", "Jet_btagDeepFlavB", "good_bjet_collection__jerUncDown", 0);
    auto df183 = quantities::jet::btagValue(df182, "btag_value_1__jerUncUp", "Jet_btagDeepFlavB", "good_bjet_collection__jerUncUp", 0);
    auto df184 = quantities::jet::btagValue(df183, "btag_value_1__jesUncEC2YearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncEC2YearDown", 0);
    auto df185 = quantities::jet::btagValue(df184, "btag_value_1__jesUncBBEC1Down", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncBBEC1Down", 0);
    auto df186 = quantities::jet::btagValue(df185, "btag_value_1__jesUncEC2Down", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncEC2Down", 0);
    auto df187 = quantities::jet::btagValue(df186, "btag_value_1__jesUncAbsoluteYearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncAbsoluteYearDown", 0);
    auto df188 = quantities::jet::btagValue(df187, "btag_value_1__jesUncRelativeBalDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncRelativeBalDown", 0);
    auto df189 = quantities::jet::btagValue(df188, "btag_value_1__jesUncTotalUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncTotalUp", 0);
    auto df190 = quantities::jet::btagValue(df189, "btag_value_1__jesUncBBEC1YearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncBBEC1YearUp", 0);
    auto df191 = quantities::jet::btagValue(df190, "btag_value_1__jesUncHEMIssueUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHEMIssueUp", 0);
    auto df192 = quantities::jet::btagValue(df191, "btag_value_1__jesUncRelativeSampleYearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncRelativeSampleYearDown", 0);
    auto df193 = quantities::jet::btagValue(df192, "btag_value_1__jesUncHFUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHFUp", 0);
    auto df194 = quantities::jet::btagValue(df193, "btag_value_1__jesUncFlavorQCDDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncFlavorQCDDown", 0);
    auto df195 = quantities::jet::btagValue(df194, "btag_value_1__jesUncHEMIssueDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHEMIssueDown", 0);
    auto df196 = quantities::jet::btagValue(df195, "btag_value_1__jesUncAbsoluteUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncAbsoluteUp", 0);
    auto df197 = quantities::jet::btagValue(df196, "btag_value_1__jesUncEC2YearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncEC2YearUp", 0);
    auto df198 = quantities::jet::btagValue(df197, "btag_value_1__jesUncEC2Up", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncEC2Up", 0);
    auto df199 = quantities::jet::btagValue(df198, "btag_value_1__jesUncBBEC1Up", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncBBEC1Up", 0);
    auto df200 = quantities::jet::btagValue(df199, "btag_value_1__jesUncAbsoluteYearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncAbsoluteYearUp", 0);
    auto df201 = quantities::jet::btagValue(df200, "btag_value_1__jesUncHFYearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHFYearUp", 0);
    auto df202 = quantities::jet::btagValue(df201, "btag_value_1__jesUncHFYearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHFYearDown", 0);
    auto df203 = quantities::jet::btagValue(df202, "btag_value_1__jesUncBBEC1YearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncBBEC1YearDown", 0);
    auto df204 = quantities::pt(df203, "bpt_2", "bjet_p4_2");
    auto df205 = quantities::pt(df204, "bpt_2__jesUncFlavorQCDUp", "bjet_p4_2__jesUncFlavorQCDUp");
    auto df206 = quantities::pt(df205, "bpt_2__jesUncHFDown", "bjet_p4_2__jesUncHFDown");
    auto df207 = quantities::pt(df206, "bpt_2__jesUncRelativeBalUp", "bjet_p4_2__jesUncRelativeBalUp");
    auto df208 = quantities::pt(df207, "bpt_2__jesUncTotalDown", "bjet_p4_2__jesUncTotalDown");
    auto df209 = quantities::pt(df208, "bpt_2__jesUncRelativeSampleYearUp", "bjet_p4_2__jesUncRelativeSampleYearUp");
    auto df210 = quantities::pt(df209, "bpt_2__jesUncAbsoluteDown", "bjet_p4_2__jesUncAbsoluteDown");
    auto df211 = quantities::pt(df210, "bpt_2__jerUncDown", "bjet_p4_2__jerUncDown");
    auto df212 = quantities::pt(df211, "bpt_2__jerUncUp", "bjet_p4_2__jerUncUp");
    auto df213 = quantities::pt(df212, "bpt_2__jesUncEC2YearDown", "bjet_p4_2__jesUncEC2YearDown");
    auto df214 = quantities::pt(df213, "bpt_2__jesUncBBEC1Down", "bjet_p4_2__jesUncBBEC1Down");
    auto df215 = quantities::pt(df214, "bpt_2__jesUncEC2Down", "bjet_p4_2__jesUncEC2Down");
    auto df216 = quantities::pt(df215, "bpt_2__jesUncAbsoluteYearDown", "bjet_p4_2__jesUncAbsoluteYearDown");
    auto df217 = quantities::pt(df216, "bpt_2__jesUncRelativeBalDown", "bjet_p4_2__jesUncRelativeBalDown");
    auto df218 = quantities::pt(df217, "bpt_2__jesUncTotalUp", "bjet_p4_2__jesUncTotalUp");
    auto df219 = quantities::pt(df218, "bpt_2__jesUncBBEC1YearUp", "bjet_p4_2__jesUncBBEC1YearUp");
    auto df220 = quantities::pt(df219, "bpt_2__jesUncHEMIssueUp", "bjet_p4_2__jesUncHEMIssueUp");
    auto df221 = quantities::pt(df220, "bpt_2__jesUncRelativeSampleYearDown", "bjet_p4_2__jesUncRelativeSampleYearDown");
    auto df222 = quantities::pt(df221, "bpt_2__jesUncHFUp", "bjet_p4_2__jesUncHFUp");
    auto df223 = quantities::pt(df222, "bpt_2__jesUncFlavorQCDDown", "bjet_p4_2__jesUncFlavorQCDDown");
    auto df224 = quantities::pt(df223, "bpt_2__jesUncHEMIssueDown", "bjet_p4_2__jesUncHEMIssueDown");
    auto df225 = quantities::pt(df224, "bpt_2__jesUncAbsoluteUp", "bjet_p4_2__jesUncAbsoluteUp");
    auto df226 = quantities::pt(df225, "bpt_2__jesUncEC2YearUp", "bjet_p4_2__jesUncEC2YearUp");
    auto df227 = quantities::pt(df226, "bpt_2__jesUncEC2Up", "bjet_p4_2__jesUncEC2Up");
    auto df228 = quantities::pt(df227, "bpt_2__jesUncBBEC1Up", "bjet_p4_2__jesUncBBEC1Up");
    auto df229 = quantities::pt(df228, "bpt_2__jesUncAbsoluteYearUp", "bjet_p4_2__jesUncAbsoluteYearUp");
    auto df230 = quantities::pt(df229, "bpt_2__jesUncHFYearUp", "bjet_p4_2__jesUncHFYearUp");
    auto df231 = quantities::pt(df230, "bpt_2__jesUncHFYearDown", "bjet_p4_2__jesUncHFYearDown");
    auto df232 = quantities::pt(df231, "bpt_2__jesUncBBEC1YearDown", "bjet_p4_2__jesUncBBEC1YearDown");
    auto df233 = quantities::eta(df232, "beta_2", "bjet_p4_2");
    auto df234 = quantities::eta(df233, "beta_2__jesUncFlavorQCDUp", "bjet_p4_2__jesUncFlavorQCDUp");
    auto df235 = quantities::eta(df234, "beta_2__jesUncHFDown", "bjet_p4_2__jesUncHFDown");
    auto df236 = quantities::eta(df235, "beta_2__jesUncRelativeBalUp", "bjet_p4_2__jesUncRelativeBalUp");
    auto df237 = quantities::eta(df236, "beta_2__jesUncTotalDown", "bjet_p4_2__jesUncTotalDown");
    auto df238 = quantities::eta(df237, "beta_2__jesUncRelativeSampleYearUp", "bjet_p4_2__jesUncRelativeSampleYearUp");
    auto df239 = quantities::eta(df238, "beta_2__jesUncAbsoluteDown", "bjet_p4_2__jesUncAbsoluteDown");
    auto df240 = quantities::eta(df239, "beta_2__jerUncDown", "bjet_p4_2__jerUncDown");
    auto df241 = quantities::eta(df240, "beta_2__jerUncUp", "bjet_p4_2__jerUncUp");
    auto df242 = quantities::eta(df241, "beta_2__jesUncEC2YearDown", "bjet_p4_2__jesUncEC2YearDown");
    auto df243 = quantities::eta(df242, "beta_2__jesUncBBEC1Down", "bjet_p4_2__jesUncBBEC1Down");
    auto df244 = quantities::eta(df243, "beta_2__jesUncEC2Down", "bjet_p4_2__jesUncEC2Down");
    auto df245 = quantities::eta(df244, "beta_2__jesUncAbsoluteYearDown", "bjet_p4_2__jesUncAbsoluteYearDown");
    auto df246 = quantities::eta(df245, "beta_2__jesUncRelativeBalDown", "bjet_p4_2__jesUncRelativeBalDown");
    auto df247 = quantities::eta(df246, "beta_2__jesUncTotalUp", "bjet_p4_2__jesUncTotalUp");
    auto df248 = quantities::eta(df247, "beta_2__jesUncBBEC1YearUp", "bjet_p4_2__jesUncBBEC1YearUp");
    auto df249 = quantities::eta(df248, "beta_2__jesUncHEMIssueUp", "bjet_p4_2__jesUncHEMIssueUp");
    auto df250 = quantities::eta(df249, "beta_2__jesUncRelativeSampleYearDown", "bjet_p4_2__jesUncRelativeSampleYearDown");
    auto df251 = quantities::eta(df250, "beta_2__jesUncHFUp", "bjet_p4_2__jesUncHFUp");
    auto df252 = quantities::eta(df251, "beta_2__jesUncFlavorQCDDown", "bjet_p4_2__jesUncFlavorQCDDown");
    auto df253 = quantities::eta(df252, "beta_2__jesUncHEMIssueDown", "bjet_p4_2__jesUncHEMIssueDown");
    auto df254 = quantities::eta(df253, "beta_2__jesUncAbsoluteUp", "bjet_p4_2__jesUncAbsoluteUp");
    auto df255 = quantities::eta(df254, "beta_2__jesUncEC2YearUp", "bjet_p4_2__jesUncEC2YearUp");
    auto df256 = quantities::eta(df255, "beta_2__jesUncEC2Up", "bjet_p4_2__jesUncEC2Up");
    auto df257 = quantities::eta(df256, "beta_2__jesUncBBEC1Up", "bjet_p4_2__jesUncBBEC1Up");
    auto df258 = quantities::eta(df257, "beta_2__jesUncAbsoluteYearUp", "bjet_p4_2__jesUncAbsoluteYearUp");
    auto df259 = quantities::eta(df258, "beta_2__jesUncHFYearUp", "bjet_p4_2__jesUncHFYearUp");
    auto df260 = quantities::eta(df259, "beta_2__jesUncHFYearDown", "bjet_p4_2__jesUncHFYearDown");
    auto df261 = quantities::eta(df260, "beta_2__jesUncBBEC1YearDown", "bjet_p4_2__jesUncBBEC1YearDown");
    auto df262 = quantities::phi(df261, "bphi_2", "bjet_p4_2");
    auto df263 = quantities::phi(df262, "bphi_2__jesUncFlavorQCDUp", "bjet_p4_2__jesUncFlavorQCDUp");
    auto df264 = quantities::phi(df263, "bphi_2__jesUncHFDown", "bjet_p4_2__jesUncHFDown");
    auto df265 = quantities::phi(df264, "bphi_2__jesUncRelativeBalUp", "bjet_p4_2__jesUncRelativeBalUp");
    auto df266 = quantities::phi(df265, "bphi_2__jesUncTotalDown", "bjet_p4_2__jesUncTotalDown");
    auto df267 = quantities::phi(df266, "bphi_2__jesUncRelativeSampleYearUp", "bjet_p4_2__jesUncRelativeSampleYearUp");
    auto df268 = quantities::phi(df267, "bphi_2__jesUncAbsoluteDown", "bjet_p4_2__jesUncAbsoluteDown");
    auto df269 = quantities::phi(df268, "bphi_2__jerUncDown", "bjet_p4_2__jerUncDown");
    auto df270 = quantities::phi(df269, "bphi_2__jerUncUp", "bjet_p4_2__jerUncUp");
    auto df271 = quantities::phi(df270, "bphi_2__jesUncEC2YearDown", "bjet_p4_2__jesUncEC2YearDown");
    auto df272 = quantities::phi(df271, "bphi_2__jesUncBBEC1Down", "bjet_p4_2__jesUncBBEC1Down");
    auto df273 = quantities::phi(df272, "bphi_2__jesUncEC2Down", "bjet_p4_2__jesUncEC2Down");
    auto df274 = quantities::phi(df273, "bphi_2__jesUncAbsoluteYearDown", "bjet_p4_2__jesUncAbsoluteYearDown");
    auto df275 = quantities::phi(df274, "bphi_2__jesUncRelativeBalDown", "bjet_p4_2__jesUncRelativeBalDown");
    auto df276 = quantities::phi(df275, "bphi_2__jesUncTotalUp", "bjet_p4_2__jesUncTotalUp");
    auto df277 = quantities::phi(df276, "bphi_2__jesUncBBEC1YearUp", "bjet_p4_2__jesUncBBEC1YearUp");
    auto df278 = quantities::phi(df277, "bphi_2__jesUncHEMIssueUp", "bjet_p4_2__jesUncHEMIssueUp");
    auto df279 = quantities::phi(df278, "bphi_2__jesUncRelativeSampleYearDown", "bjet_p4_2__jesUncRelativeSampleYearDown");
    auto df280 = quantities::phi(df279, "bphi_2__jesUncHFUp", "bjet_p4_2__jesUncHFUp");
    auto df281 = quantities::phi(df280, "bphi_2__jesUncFlavorQCDDown", "bjet_p4_2__jesUncFlavorQCDDown");
    auto df282 = quantities::phi(df281, "bphi_2__jesUncHEMIssueDown", "bjet_p4_2__jesUncHEMIssueDown");
    auto df283 = quantities::phi(df282, "bphi_2__jesUncAbsoluteUp", "bjet_p4_2__jesUncAbsoluteUp");
    auto df284 = quantities::phi(df283, "bphi_2__jesUncEC2YearUp", "bjet_p4_2__jesUncEC2YearUp");
    auto df285 = quantities::phi(df284, "bphi_2__jesUncEC2Up", "bjet_p4_2__jesUncEC2Up");
    auto df286 = quantities::phi(df285, "bphi_2__jesUncBBEC1Up", "bjet_p4_2__jesUncBBEC1Up");
    auto df287 = quantities::phi(df286, "bphi_2__jesUncAbsoluteYearUp", "bjet_p4_2__jesUncAbsoluteYearUp");
    auto df288 = quantities::phi(df287, "bphi_2__jesUncHFYearUp", "bjet_p4_2__jesUncHFYearUp");
    auto df289 = quantities::phi(df288, "bphi_2__jesUncHFYearDown", "bjet_p4_2__jesUncHFYearDown");
    auto df290 = quantities::phi(df289, "bphi_2__jesUncBBEC1YearDown", "bjet_p4_2__jesUncBBEC1YearDown");
    auto df291 = quantities::jet::btagValue(df290, "btag_value_2", "Jet_btagDeepFlavB", "good_bjet_collection", 1);
    auto df292 = quantities::jet::btagValue(df291, "btag_value_2__jesUncFlavorQCDUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncFlavorQCDUp", 1);
    auto df293 = quantities::jet::btagValue(df292, "btag_value_2__jesUncHFDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHFDown", 1);
    auto df294 = quantities::jet::btagValue(df293, "btag_value_2__jesUncRelativeBalUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncRelativeBalUp", 1);
    auto df295 = quantities::jet::btagValue(df294, "btag_value_2__jesUncTotalDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncTotalDown", 1);
    auto df296 = quantities::jet::btagValue(df295, "btag_value_2__jesUncRelativeSampleYearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncRelativeSampleYearUp", 1);
    auto df297 = quantities::jet::btagValue(df296, "btag_value_2__jesUncAbsoluteDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncAbsoluteDown", 1);
    auto df298 = quantities::jet::btagValue(df297, "btag_value_2__jerUncDown", "Jet_btagDeepFlavB", "good_bjet_collection__jerUncDown", 1);
    auto df299 = quantities::jet::btagValue(df298, "btag_value_2__jerUncUp", "Jet_btagDeepFlavB", "good_bjet_collection__jerUncUp", 1);
    auto df300 = quantities::jet::btagValue(df299, "btag_value_2__jesUncEC2YearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncEC2YearDown", 1);
    auto df301 = quantities::jet::btagValue(df300, "btag_value_2__jesUncBBEC1Down", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncBBEC1Down", 1);
    auto df302 = quantities::jet::btagValue(df301, "btag_value_2__jesUncEC2Down", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncEC2Down", 1);
    auto df303 = quantities::jet::btagValue(df302, "btag_value_2__jesUncAbsoluteYearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncAbsoluteYearDown", 1);
    auto df304 = quantities::jet::btagValue(df303, "btag_value_2__jesUncRelativeBalDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncRelativeBalDown", 1);
    auto df305 = quantities::jet::btagValue(df304, "btag_value_2__jesUncTotalUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncTotalUp", 1);
    auto df306 = quantities::jet::btagValue(df305, "btag_value_2__jesUncBBEC1YearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncBBEC1YearUp", 1);
    auto df307 = quantities::jet::btagValue(df306, "btag_value_2__jesUncHEMIssueUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHEMIssueUp", 1);
    auto df308 = quantities::jet::btagValue(df307, "btag_value_2__jesUncRelativeSampleYearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncRelativeSampleYearDown", 1);
    auto df309 = quantities::jet::btagValue(df308, "btag_value_2__jesUncHFUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHFUp", 1);
    auto df310 = quantities::jet::btagValue(df309, "btag_value_2__jesUncFlavorQCDDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncFlavorQCDDown", 1);
    auto df311 = quantities::jet::btagValue(df310, "btag_value_2__jesUncHEMIssueDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHEMIssueDown", 1);
    auto df312 = quantities::jet::btagValue(df311, "btag_value_2__jesUncAbsoluteUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncAbsoluteUp", 1);
    auto df313 = quantities::jet::btagValue(df312, "btag_value_2__jesUncEC2YearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncEC2YearUp", 1);
    auto df314 = quantities::jet::btagValue(df313, "btag_value_2__jesUncEC2Up", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncEC2Up", 1);
    auto df315 = quantities::jet::btagValue(df314, "btag_value_2__jesUncBBEC1Up", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncBBEC1Up", 1);
    auto df316 = quantities::jet::btagValue(df315, "btag_value_2__jesUncAbsoluteYearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncAbsoluteYearUp", 1);
    auto df317 = quantities::jet::btagValue(df316, "btag_value_2__jesUncHFYearUp", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHFYearUp", 1);
    auto df318 = quantities::jet::btagValue(df317, "btag_value_2__jesUncHFYearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncHFYearDown", 1);
    auto df319 = quantities::jet::btagValue(df318, "btag_value_2__jesUncBBEC1YearDown", "Jet_btagDeepFlavB", "good_bjet_collection__jesUncBBEC1YearDown", 1);
    return df319;

}
