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
ROOT::RDF::RNode btagging_SF_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = scalefactor::jet::btagSF(df0, correctionManager, "Jet_pt_corrected", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask", "good_bjets_mask", "jet_overlap_veto_mask", "central", "btag_weight", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df2 = scalefactor::jet::btagSF(df1, correctionManager, "Jet_pt_corrected__jesUncFlavorQCDUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncFlavorQCDUp", "good_bjets_mask__jesUncFlavorQCDUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncFlavorQCDUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df3 = scalefactor::jet::btagSF(df2, correctionManager, "Jet_pt_corrected__jesUncHFDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncHFDown", "good_bjets_mask__jesUncHFDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncHFDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df4 = scalefactor::jet::btagSF(df3, correctionManager, "Jet_pt_corrected__jesUncRelativeBalUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncRelativeBalUp", "good_bjets_mask__jesUncRelativeBalUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncRelativeBalUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df5 = scalefactor::jet::btagSF(df4, correctionManager, "Jet_pt_corrected__jesUncTotalDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncTotalDown", "good_bjets_mask__jesUncTotalDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncTotalDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df6 = scalefactor::jet::btagSF(df5, correctionManager, "Jet_pt_corrected__jesUncRelativeSampleYearUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncRelativeSampleYearUp", "good_bjets_mask__jesUncRelativeSampleYearUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncRelativeSampleYearUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df7 = scalefactor::jet::btagSF(df6, correctionManager, "Jet_pt_corrected__jesUncAbsoluteDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncAbsoluteDown", "good_bjets_mask__jesUncAbsoluteDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncAbsoluteDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df8 = scalefactor::jet::btagSF(df7, correctionManager, "Jet_pt_corrected__jerUncDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jerUncDown", "good_bjets_mask__jerUncDown", "jet_overlap_veto_mask", "central", "btag_weight__jerUncDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df9 = scalefactor::jet::btagSF(df8, correctionManager, "Jet_pt_corrected__jerUncUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jerUncUp", "good_bjets_mask__jerUncUp", "jet_overlap_veto_mask", "central", "btag_weight__jerUncUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df10 = scalefactor::jet::btagSF(df9, correctionManager, "Jet_pt_corrected", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask", "good_bjets_mask", "jet_overlap_veto_mask__eleEsResoDown", "central", "btag_weight__eleEsResoDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df11 = scalefactor::jet::btagSF(df10, correctionManager, "Jet_pt_corrected__jesUncEC2YearDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncEC2YearDown", "good_bjets_mask__jesUncEC2YearDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncEC2YearDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df12 = scalefactor::jet::btagSF(df11, correctionManager, "Jet_pt_corrected__jesUncBBEC1Down", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncBBEC1Down", "good_bjets_mask__jesUncBBEC1Down", "jet_overlap_veto_mask", "central", "btag_weight__jesUncBBEC1Down", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df13 = scalefactor::jet::btagSF(df12, correctionManager, "Jet_pt_corrected", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask", "good_bjets_mask", "jet_overlap_veto_mask__eleEsResoUp", "central", "btag_weight__eleEsResoUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df14 = scalefactor::jet::btagSF(df13, correctionManager, "Jet_pt_corrected__jesUncEC2Down", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncEC2Down", "good_bjets_mask__jesUncEC2Down", "jet_overlap_veto_mask", "central", "btag_weight__jesUncEC2Down", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df15 = scalefactor::jet::btagSF(df14, correctionManager, "Jet_pt_corrected__jesUncAbsoluteYearDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncAbsoluteYearDown", "good_bjets_mask__jesUncAbsoluteYearDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncAbsoluteYearDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df16 = scalefactor::jet::btagSF(df15, correctionManager, "Jet_pt_corrected__jesUncRelativeBalDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncRelativeBalDown", "good_bjets_mask__jesUncRelativeBalDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncRelativeBalDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df17 = scalefactor::jet::btagSF(df16, correctionManager, "Jet_pt_corrected__jesUncTotalUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncTotalUp", "good_bjets_mask__jesUncTotalUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncTotalUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df18 = scalefactor::jet::btagSF(df17, correctionManager, "Jet_pt_corrected", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask", "good_bjets_mask", "jet_overlap_veto_mask__eleEsScaleUp", "central", "btag_weight__eleEsScaleUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df19 = scalefactor::jet::btagSF(df18, correctionManager, "Jet_pt_corrected__jesUncBBEC1YearUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncBBEC1YearUp", "good_bjets_mask__jesUncBBEC1YearUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncBBEC1YearUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df20 = scalefactor::jet::btagSF(df19, correctionManager, "Jet_pt_corrected__jesUncHEMIssueUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncHEMIssueUp", "good_bjets_mask__jesUncHEMIssueUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncHEMIssueUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df21 = scalefactor::jet::btagSF(df20, correctionManager, "Jet_pt_corrected__jesUncRelativeSampleYearDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncRelativeSampleYearDown", "good_bjets_mask__jesUncRelativeSampleYearDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncRelativeSampleYearDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df22 = scalefactor::jet::btagSF(df21, correctionManager, "Jet_pt_corrected__jesUncHFUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncHFUp", "good_bjets_mask__jesUncHFUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncHFUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df23 = scalefactor::jet::btagSF(df22, correctionManager, "Jet_pt_corrected__jesUncFlavorQCDDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncFlavorQCDDown", "good_bjets_mask__jesUncFlavorQCDDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncFlavorQCDDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df24 = scalefactor::jet::btagSF(df23, correctionManager, "Jet_pt_corrected__jesUncHEMIssueDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncHEMIssueDown", "good_bjets_mask__jesUncHEMIssueDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncHEMIssueDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df25 = scalefactor::jet::btagSF(df24, correctionManager, "Jet_pt_corrected__jesUncAbsoluteUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncAbsoluteUp", "good_bjets_mask__jesUncAbsoluteUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncAbsoluteUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df26 = scalefactor::jet::btagSF(df25, correctionManager, "Jet_pt_corrected__jesUncEC2YearUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncEC2YearUp", "good_bjets_mask__jesUncEC2YearUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncEC2YearUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df27 = scalefactor::jet::btagSF(df26, correctionManager, "Jet_pt_corrected", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask", "good_bjets_mask", "jet_overlap_veto_mask__eleEsScaleDown", "central", "btag_weight__eleEsScaleDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df28 = scalefactor::jet::btagSF(df27, correctionManager, "Jet_pt_corrected__jesUncEC2Up", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncEC2Up", "good_bjets_mask__jesUncEC2Up", "jet_overlap_veto_mask", "central", "btag_weight__jesUncEC2Up", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df29 = scalefactor::jet::btagSF(df28, correctionManager, "Jet_pt_corrected__jesUncBBEC1Up", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncBBEC1Up", "good_bjets_mask__jesUncBBEC1Up", "jet_overlap_veto_mask", "central", "btag_weight__jesUncBBEC1Up", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df30 = scalefactor::jet::btagSF(df29, correctionManager, "Jet_pt_corrected__jesUncAbsoluteYearUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncAbsoluteYearUp", "good_bjets_mask__jesUncAbsoluteYearUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncAbsoluteYearUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df31 = scalefactor::jet::btagSF(df30, correctionManager, "Jet_pt_corrected__jesUncHFYearUp", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncHFYearUp", "good_bjets_mask__jesUncHFYearUp", "jet_overlap_veto_mask", "central", "btag_weight__jesUncHFYearUp", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df32 = scalefactor::jet::btagSF(df31, correctionManager, "Jet_pt_corrected__jesUncHFYearDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncHFYearDown", "good_bjets_mask__jesUncHFYearDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncHFYearDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    auto df33 = scalefactor::jet::btagSF(df32, correctionManager, "Jet_pt_corrected__jesUncBBEC1YearDown", "Jet_eta", "Jet_btagDeepFlavB", "Jet_hadronFlavour", "good_jets_mask__jesUncBBEC1YearDown", "good_bjets_mask__jesUncBBEC1YearDown", "jet_overlap_veto_mask", "central", "btag_weight__jesUncBBEC1YearDown", "data/jsonpog-integration/POG/BTV/2018_UL/btagging.json.gz", "deepJet_shape");
    return df33;

}
