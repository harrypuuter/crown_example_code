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
ROOT::RDF::RNode GoodElectrons_et (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::CutPt(df0, "Electron_pt_corrected", "PG_internal_quantity_7", 25.0);
    auto df2 = physicsobject::CutPt(df1, "Electron_pt_corrected__eleEsResoDown", "PG_internal_quantity_7__eleEsResoDown", 25.0);
    auto df3 = physicsobject::CutPt(df2, "Electron_pt_corrected__eleEsScaleUp", "PG_internal_quantity_7__eleEsScaleUp", 25.0);
    auto df4 = physicsobject::CutPt(df3, "Electron_pt_corrected__eleEsResoUp", "PG_internal_quantity_7__eleEsResoUp", 25.0);
    auto df5 = physicsobject::CutPt(df4, "Electron_pt_corrected__eleEsScaleDown", "PG_internal_quantity_7__eleEsScaleDown", 25.0);
    auto df6 = physicsobject::CutEta(df5, "Electron_eta", "PG_internal_quantity_8", 2.1);
    auto df7 = physicsobject::electron::CutIsolation(df6, "PG_internal_quantity_9", "Electron_pfRelIso03_all", 0.5);
    auto df8 = physicsobject::CombineMasks(df7, "good_electrons_mask", "base_electrons_mask", "PG_internal_quantity_7", "PG_internal_quantity_8", "PG_internal_quantity_9");
    auto df9 = physicsobject::CombineMasks(df8, "good_electrons_mask__eleEsResoDown", "base_electrons_mask__eleEsResoDown", "PG_internal_quantity_7__eleEsResoDown", "PG_internal_quantity_8", "PG_internal_quantity_9");
    auto df10 = physicsobject::CombineMasks(df9, "good_electrons_mask__eleEsScaleUp", "base_electrons_mask__eleEsScaleUp", "PG_internal_quantity_7__eleEsScaleUp", "PG_internal_quantity_8", "PG_internal_quantity_9");
    auto df11 = physicsobject::CombineMasks(df10, "good_electrons_mask__eleEsResoUp", "base_electrons_mask__eleEsResoUp", "PG_internal_quantity_7__eleEsResoUp", "PG_internal_quantity_8", "PG_internal_quantity_9");
    auto df12 = physicsobject::CombineMasks(df11, "good_electrons_mask__eleEsScaleDown", "base_electrons_mask__eleEsScaleDown", "PG_internal_quantity_7__eleEsScaleDown", "PG_internal_quantity_8", "PG_internal_quantity_9");
    return df12;

}
