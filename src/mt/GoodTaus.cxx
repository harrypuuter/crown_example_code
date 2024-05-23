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
ROOT::RDF::RNode GoodTaus_mt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::CutPt(df0, "Tau_pt_corrected", "PG_internal_quantity_38", 20.0);
    auto df2 = physicsobject::CutPt(df1, "Tau_pt_corrected__tauEs3prong1pizeroDown", "PG_internal_quantity_38__tauEs3prong1pizeroDown", 20.0);
    auto df3 = physicsobject::CutPt(df2, "Tau_pt_corrected__tauEs1prong0pizeroDown", "PG_internal_quantity_38__tauEs1prong0pizeroDown", 20.0);
    auto df4 = physicsobject::CutPt(df3, "Tau_pt_corrected__tauEs3prong1pizeroUp", "PG_internal_quantity_38__tauEs3prong1pizeroUp", 20.0);
    auto df5 = physicsobject::CutPt(df4, "Tau_pt_corrected__tauEs1prong1pizeroDown", "PG_internal_quantity_38__tauEs1prong1pizeroDown", 20.0);
    auto df6 = physicsobject::CutPt(df5, "Tau_pt_corrected__tauEs1prong1pizeroUp", "PG_internal_quantity_38__tauEs1prong1pizeroUp", 20.0);
    auto df7 = physicsobject::CutPt(df6, "Tau_pt_corrected__tauEs1prong0pizeroUp", "PG_internal_quantity_38__tauEs1prong0pizeroUp", 20.0);
    auto df8 = physicsobject::CutPt(df7, "Tau_pt_corrected__tauEs3prong0pizeroDown", "PG_internal_quantity_38__tauEs3prong0pizeroDown", 20.0);
    auto df9 = physicsobject::CutPt(df8, "Tau_pt_corrected__tauEs3prong0pizeroUp", "PG_internal_quantity_38__tauEs3prong0pizeroUp", 20.0);
    auto df10 = physicsobject::CutEta(df9, "Tau_eta", "PG_internal_quantity_39", 2.3);
    auto df11 = physicsobject::CutDz(df10, "Tau_dz", "PG_internal_quantity_40", 0.2);
    auto df12 = physicsobject::tau::CutDecayModes(df11, "PG_internal_quantity_41", "Tau_decayMode", {0,1,10,11});
    auto df13 = physicsobject::tau::CutTauID(df12, "PG_internal_quantity_42", "Tau_idDeepTau2017v2p1VSjet", 1);
    auto df14 = physicsobject::tau::CutTauID(df13, "PG_internal_quantity_43", "Tau_idDeepTau2017v2p1VSe", 1);
    auto df15 = physicsobject::tau::CutTauID(df14, "PG_internal_quantity_44", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df16 = physicsobject::CombineMasks(df15, "good_taus_mask", "PG_internal_quantity_38", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    auto df17 = physicsobject::CombineMasks(df16, "good_taus_mask__tauEs3prong1pizeroDown", "PG_internal_quantity_38__tauEs3prong1pizeroDown", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    auto df18 = physicsobject::CombineMasks(df17, "good_taus_mask__tauEs1prong0pizeroDown", "PG_internal_quantity_38__tauEs1prong0pizeroDown", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    auto df19 = physicsobject::CombineMasks(df18, "good_taus_mask__tauEs3prong1pizeroUp", "PG_internal_quantity_38__tauEs3prong1pizeroUp", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    auto df20 = physicsobject::CombineMasks(df19, "good_taus_mask__tauEs1prong1pizeroDown", "PG_internal_quantity_38__tauEs1prong1pizeroDown", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    auto df21 = physicsobject::CombineMasks(df20, "good_taus_mask__tauEs1prong1pizeroUp", "PG_internal_quantity_38__tauEs1prong1pizeroUp", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    auto df22 = physicsobject::CombineMasks(df21, "good_taus_mask__tauEs1prong0pizeroUp", "PG_internal_quantity_38__tauEs1prong0pizeroUp", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    auto df23 = physicsobject::CombineMasks(df22, "good_taus_mask__tauEs3prong0pizeroDown", "PG_internal_quantity_38__tauEs3prong0pizeroDown", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    auto df24 = physicsobject::CombineMasks(df23, "good_taus_mask__tauEs3prong0pizeroUp", "PG_internal_quantity_38__tauEs3prong0pizeroUp", "PG_internal_quantity_39", "PG_internal_quantity_40", "PG_internal_quantity_41", "PG_internal_quantity_42", "PG_internal_quantity_43", "PG_internal_quantity_44");
    return df24;

}
