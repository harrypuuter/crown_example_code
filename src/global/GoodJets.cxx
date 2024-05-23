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
ROOT::RDF::RNode GoodJets_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::CutPt(df0, "Jet_pt_corrected", "PG_internal_quantity_25", 30);
    auto df2 = physicsobject::CutPt(df1, "Jet_pt_corrected__jesUncFlavorQCDUp", "PG_internal_quantity_25__jesUncFlavorQCDUp", 30);
    auto df3 = physicsobject::CutPt(df2, "Jet_pt_corrected__jesUncHFDown", "PG_internal_quantity_25__jesUncHFDown", 30);
    auto df4 = physicsobject::CutPt(df3, "Jet_pt_corrected__jesUncRelativeBalUp", "PG_internal_quantity_25__jesUncRelativeBalUp", 30);
    auto df5 = physicsobject::CutPt(df4, "Jet_pt_corrected__jesUncTotalDown", "PG_internal_quantity_25__jesUncTotalDown", 30);
    auto df6 = physicsobject::CutPt(df5, "Jet_pt_corrected__jesUncRelativeSampleYearUp", "PG_internal_quantity_25__jesUncRelativeSampleYearUp", 30);
    auto df7 = physicsobject::CutPt(df6, "Jet_pt_corrected__jesUncAbsoluteDown", "PG_internal_quantity_25__jesUncAbsoluteDown", 30);
    auto df8 = physicsobject::CutPt(df7, "Jet_pt_corrected__jerUncDown", "PG_internal_quantity_25__jerUncDown", 30);
    auto df9 = physicsobject::CutPt(df8, "Jet_pt_corrected__jerUncUp", "PG_internal_quantity_25__jerUncUp", 30);
    auto df10 = physicsobject::CutPt(df9, "Jet_pt_corrected__jesUncEC2YearDown", "PG_internal_quantity_25__jesUncEC2YearDown", 30);
    auto df11 = physicsobject::CutPt(df10, "Jet_pt_corrected__jesUncBBEC1Down", "PG_internal_quantity_25__jesUncBBEC1Down", 30);
    auto df12 = physicsobject::CutPt(df11, "Jet_pt_corrected__jesUncEC2Down", "PG_internal_quantity_25__jesUncEC2Down", 30);
    auto df13 = physicsobject::CutPt(df12, "Jet_pt_corrected__jesUncAbsoluteYearDown", "PG_internal_quantity_25__jesUncAbsoluteYearDown", 30);
    auto df14 = physicsobject::CutPt(df13, "Jet_pt_corrected__jesUncRelativeBalDown", "PG_internal_quantity_25__jesUncRelativeBalDown", 30);
    auto df15 = physicsobject::CutPt(df14, "Jet_pt_corrected__jesUncTotalUp", "PG_internal_quantity_25__jesUncTotalUp", 30);
    auto df16 = physicsobject::CutPt(df15, "Jet_pt_corrected__jesUncBBEC1YearUp", "PG_internal_quantity_25__jesUncBBEC1YearUp", 30);
    auto df17 = physicsobject::CutPt(df16, "Jet_pt_corrected__jesUncHEMIssueUp", "PG_internal_quantity_25__jesUncHEMIssueUp", 30);
    auto df18 = physicsobject::CutPt(df17, "Jet_pt_corrected__jesUncRelativeSampleYearDown", "PG_internal_quantity_25__jesUncRelativeSampleYearDown", 30);
    auto df19 = physicsobject::CutPt(df18, "Jet_pt_corrected__jesUncHFUp", "PG_internal_quantity_25__jesUncHFUp", 30);
    auto df20 = physicsobject::CutPt(df19, "Jet_pt_corrected__jesUncFlavorQCDDown", "PG_internal_quantity_25__jesUncFlavorQCDDown", 30);
    auto df21 = physicsobject::CutPt(df20, "Jet_pt_corrected__jesUncHEMIssueDown", "PG_internal_quantity_25__jesUncHEMIssueDown", 30);
    auto df22 = physicsobject::CutPt(df21, "Jet_pt_corrected__jesUncAbsoluteUp", "PG_internal_quantity_25__jesUncAbsoluteUp", 30);
    auto df23 = physicsobject::CutPt(df22, "Jet_pt_corrected__jesUncEC2YearUp", "PG_internal_quantity_25__jesUncEC2YearUp", 30);
    auto df24 = physicsobject::CutPt(df23, "Jet_pt_corrected__jesUncEC2Up", "PG_internal_quantity_25__jesUncEC2Up", 30);
    auto df25 = physicsobject::CutPt(df24, "Jet_pt_corrected__jesUncBBEC1Up", "PG_internal_quantity_25__jesUncBBEC1Up", 30);
    auto df26 = physicsobject::CutPt(df25, "Jet_pt_corrected__jesUncAbsoluteYearUp", "PG_internal_quantity_25__jesUncAbsoluteYearUp", 30);
    auto df27 = physicsobject::CutPt(df26, "Jet_pt_corrected__jesUncHFYearUp", "PG_internal_quantity_25__jesUncHFYearUp", 30);
    auto df28 = physicsobject::CutPt(df27, "Jet_pt_corrected__jesUncHFYearDown", "PG_internal_quantity_25__jesUncHFYearDown", 30);
    auto df29 = physicsobject::CutPt(df28, "Jet_pt_corrected__jesUncBBEC1YearDown", "PG_internal_quantity_25__jesUncBBEC1YearDown", 30);
    auto df30 = physicsobject::CutEta(df29, "Jet_eta", "PG_internal_quantity_26", 4.7);
    auto df31 = physicsobject::jet::CutID(df30, "jet_id_mask", "Jet_jetId", 2);
    auto df32 = physicsobject::jet::CutPUID(df31, "jet_puid_mask", "Jet_puId", "Jet_pt_corrected", 4, 50);
    auto df33 = physicsobject::jet::CutPUID(df32, "jet_puid_mask__jesUncFlavorQCDUp", "Jet_puId", "Jet_pt_corrected__jesUncFlavorQCDUp", 4, 50);
    auto df34 = physicsobject::jet::CutPUID(df33, "jet_puid_mask__jesUncHFDown", "Jet_puId", "Jet_pt_corrected__jesUncHFDown", 4, 50);
    auto df35 = physicsobject::jet::CutPUID(df34, "jet_puid_mask__jesUncRelativeBalUp", "Jet_puId", "Jet_pt_corrected__jesUncRelativeBalUp", 4, 50);
    auto df36 = physicsobject::jet::CutPUID(df35, "jet_puid_mask__jesUncTotalDown", "Jet_puId", "Jet_pt_corrected__jesUncTotalDown", 4, 50);
    auto df37 = physicsobject::jet::CutPUID(df36, "jet_puid_mask__jesUncRelativeSampleYearUp", "Jet_puId", "Jet_pt_corrected__jesUncRelativeSampleYearUp", 4, 50);
    auto df38 = physicsobject::jet::CutPUID(df37, "jet_puid_mask__jesUncAbsoluteDown", "Jet_puId", "Jet_pt_corrected__jesUncAbsoluteDown", 4, 50);
    auto df39 = physicsobject::jet::CutPUID(df38, "jet_puid_mask__jerUncDown", "Jet_puId", "Jet_pt_corrected__jerUncDown", 4, 50);
    auto df40 = physicsobject::jet::CutPUID(df39, "jet_puid_mask__jerUncUp", "Jet_puId", "Jet_pt_corrected__jerUncUp", 4, 50);
    auto df41 = physicsobject::jet::CutPUID(df40, "jet_puid_mask__jesUncEC2YearDown", "Jet_puId", "Jet_pt_corrected__jesUncEC2YearDown", 4, 50);
    auto df42 = physicsobject::jet::CutPUID(df41, "jet_puid_mask__jesUncBBEC1Down", "Jet_puId", "Jet_pt_corrected__jesUncBBEC1Down", 4, 50);
    auto df43 = physicsobject::jet::CutPUID(df42, "jet_puid_mask__jesUncEC2Down", "Jet_puId", "Jet_pt_corrected__jesUncEC2Down", 4, 50);
    auto df44 = physicsobject::jet::CutPUID(df43, "jet_puid_mask__jesUncAbsoluteYearDown", "Jet_puId", "Jet_pt_corrected__jesUncAbsoluteYearDown", 4, 50);
    auto df45 = physicsobject::jet::CutPUID(df44, "jet_puid_mask__jesUncRelativeBalDown", "Jet_puId", "Jet_pt_corrected__jesUncRelativeBalDown", 4, 50);
    auto df46 = physicsobject::jet::CutPUID(df45, "jet_puid_mask__jesUncTotalUp", "Jet_puId", "Jet_pt_corrected__jesUncTotalUp", 4, 50);
    auto df47 = physicsobject::jet::CutPUID(df46, "jet_puid_mask__jesUncBBEC1YearUp", "Jet_puId", "Jet_pt_corrected__jesUncBBEC1YearUp", 4, 50);
    auto df48 = physicsobject::jet::CutPUID(df47, "jet_puid_mask__jesUncHEMIssueUp", "Jet_puId", "Jet_pt_corrected__jesUncHEMIssueUp", 4, 50);
    auto df49 = physicsobject::jet::CutPUID(df48, "jet_puid_mask__jesUncRelativeSampleYearDown", "Jet_puId", "Jet_pt_corrected__jesUncRelativeSampleYearDown", 4, 50);
    auto df50 = physicsobject::jet::CutPUID(df49, "jet_puid_mask__jesUncHFUp", "Jet_puId", "Jet_pt_corrected__jesUncHFUp", 4, 50);
    auto df51 = physicsobject::jet::CutPUID(df50, "jet_puid_mask__jesUncFlavorQCDDown", "Jet_puId", "Jet_pt_corrected__jesUncFlavorQCDDown", 4, 50);
    auto df52 = physicsobject::jet::CutPUID(df51, "jet_puid_mask__jesUncHEMIssueDown", "Jet_puId", "Jet_pt_corrected__jesUncHEMIssueDown", 4, 50);
    auto df53 = physicsobject::jet::CutPUID(df52, "jet_puid_mask__jesUncAbsoluteUp", "Jet_puId", "Jet_pt_corrected__jesUncAbsoluteUp", 4, 50);
    auto df54 = physicsobject::jet::CutPUID(df53, "jet_puid_mask__jesUncEC2YearUp", "Jet_puId", "Jet_pt_corrected__jesUncEC2YearUp", 4, 50);
    auto df55 = physicsobject::jet::CutPUID(df54, "jet_puid_mask__jesUncEC2Up", "Jet_puId", "Jet_pt_corrected__jesUncEC2Up", 4, 50);
    auto df56 = physicsobject::jet::CutPUID(df55, "jet_puid_mask__jesUncBBEC1Up", "Jet_puId", "Jet_pt_corrected__jesUncBBEC1Up", 4, 50);
    auto df57 = physicsobject::jet::CutPUID(df56, "jet_puid_mask__jesUncAbsoluteYearUp", "Jet_puId", "Jet_pt_corrected__jesUncAbsoluteYearUp", 4, 50);
    auto df58 = physicsobject::jet::CutPUID(df57, "jet_puid_mask__jesUncHFYearUp", "Jet_puId", "Jet_pt_corrected__jesUncHFYearUp", 4, 50);
    auto df59 = physicsobject::jet::CutPUID(df58, "jet_puid_mask__jesUncHFYearDown", "Jet_puId", "Jet_pt_corrected__jesUncHFYearDown", 4, 50);
    auto df60 = physicsobject::jet::CutPUID(df59, "jet_puid_mask__jesUncBBEC1YearDown", "Jet_puId", "Jet_pt_corrected__jesUncBBEC1YearDown", 4, 50);
    auto df61 = physicsobject::CombineMasks(df60, "good_jets_mask", "PG_internal_quantity_25", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask");
    auto df62 = physicsobject::CombineMasks(df61, "good_jets_mask__jesUncFlavorQCDUp", "PG_internal_quantity_25__jesUncFlavorQCDUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncFlavorQCDUp");
    auto df63 = physicsobject::CombineMasks(df62, "good_jets_mask__jesUncHFDown", "PG_internal_quantity_25__jesUncHFDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncHFDown");
    auto df64 = physicsobject::CombineMasks(df63, "good_jets_mask__jesUncRelativeBalUp", "PG_internal_quantity_25__jesUncRelativeBalUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncRelativeBalUp");
    auto df65 = physicsobject::CombineMasks(df64, "good_jets_mask__jesUncTotalDown", "PG_internal_quantity_25__jesUncTotalDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncTotalDown");
    auto df66 = physicsobject::CombineMasks(df65, "good_jets_mask__jesUncRelativeSampleYearUp", "PG_internal_quantity_25__jesUncRelativeSampleYearUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncRelativeSampleYearUp");
    auto df67 = physicsobject::CombineMasks(df66, "good_jets_mask__jesUncAbsoluteDown", "PG_internal_quantity_25__jesUncAbsoluteDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncAbsoluteDown");
    auto df68 = physicsobject::CombineMasks(df67, "good_jets_mask__jerUncDown", "PG_internal_quantity_25__jerUncDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jerUncDown");
    auto df69 = physicsobject::CombineMasks(df68, "good_jets_mask__jerUncUp", "PG_internal_quantity_25__jerUncUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jerUncUp");
    auto df70 = physicsobject::CombineMasks(df69, "good_jets_mask__jesUncEC2YearDown", "PG_internal_quantity_25__jesUncEC2YearDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncEC2YearDown");
    auto df71 = physicsobject::CombineMasks(df70, "good_jets_mask__jesUncBBEC1Down", "PG_internal_quantity_25__jesUncBBEC1Down", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncBBEC1Down");
    auto df72 = physicsobject::CombineMasks(df71, "good_jets_mask__jesUncEC2Down", "PG_internal_quantity_25__jesUncEC2Down", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncEC2Down");
    auto df73 = physicsobject::CombineMasks(df72, "good_jets_mask__jesUncAbsoluteYearDown", "PG_internal_quantity_25__jesUncAbsoluteYearDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncAbsoluteYearDown");
    auto df74 = physicsobject::CombineMasks(df73, "good_jets_mask__jesUncRelativeBalDown", "PG_internal_quantity_25__jesUncRelativeBalDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncRelativeBalDown");
    auto df75 = physicsobject::CombineMasks(df74, "good_jets_mask__jesUncTotalUp", "PG_internal_quantity_25__jesUncTotalUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncTotalUp");
    auto df76 = physicsobject::CombineMasks(df75, "good_jets_mask__jesUncBBEC1YearUp", "PG_internal_quantity_25__jesUncBBEC1YearUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncBBEC1YearUp");
    auto df77 = physicsobject::CombineMasks(df76, "good_jets_mask__jesUncHEMIssueUp", "PG_internal_quantity_25__jesUncHEMIssueUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncHEMIssueUp");
    auto df78 = physicsobject::CombineMasks(df77, "good_jets_mask__jesUncRelativeSampleYearDown", "PG_internal_quantity_25__jesUncRelativeSampleYearDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncRelativeSampleYearDown");
    auto df79 = physicsobject::CombineMasks(df78, "good_jets_mask__jesUncHFUp", "PG_internal_quantity_25__jesUncHFUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncHFUp");
    auto df80 = physicsobject::CombineMasks(df79, "good_jets_mask__jesUncFlavorQCDDown", "PG_internal_quantity_25__jesUncFlavorQCDDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncFlavorQCDDown");
    auto df81 = physicsobject::CombineMasks(df80, "good_jets_mask__jesUncHEMIssueDown", "PG_internal_quantity_25__jesUncHEMIssueDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncHEMIssueDown");
    auto df82 = physicsobject::CombineMasks(df81, "good_jets_mask__jesUncAbsoluteUp", "PG_internal_quantity_25__jesUncAbsoluteUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncAbsoluteUp");
    auto df83 = physicsobject::CombineMasks(df82, "good_jets_mask__jesUncEC2YearUp", "PG_internal_quantity_25__jesUncEC2YearUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncEC2YearUp");
    auto df84 = physicsobject::CombineMasks(df83, "good_jets_mask__jesUncEC2Up", "PG_internal_quantity_25__jesUncEC2Up", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncEC2Up");
    auto df85 = physicsobject::CombineMasks(df84, "good_jets_mask__jesUncBBEC1Up", "PG_internal_quantity_25__jesUncBBEC1Up", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncBBEC1Up");
    auto df86 = physicsobject::CombineMasks(df85, "good_jets_mask__jesUncAbsoluteYearUp", "PG_internal_quantity_25__jesUncAbsoluteYearUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncAbsoluteYearUp");
    auto df87 = physicsobject::CombineMasks(df86, "good_jets_mask__jesUncHFYearUp", "PG_internal_quantity_25__jesUncHFYearUp", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncHFYearUp");
    auto df88 = physicsobject::CombineMasks(df87, "good_jets_mask__jesUncHFYearDown", "PG_internal_quantity_25__jesUncHFYearDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncHFYearDown");
    auto df89 = physicsobject::CombineMasks(df88, "good_jets_mask__jesUncBBEC1YearDown", "PG_internal_quantity_25__jesUncBBEC1YearDown", "PG_internal_quantity_26", "jet_id_mask", "jet_puid_mask__jesUncBBEC1YearDown");
    return df89;

}
