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
ROOT::RDF::RNode BaseElectrons_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::CutPt(df0, "Electron_pt_corrected", "PG_internal_quantity_1", 10.0);
    auto df2 = physicsobject::CutPt(df1, "Electron_pt_corrected__eleEsResoDown", "PG_internal_quantity_1__eleEsResoDown", 10.0);
    auto df3 = physicsobject::CutPt(df2, "Electron_pt_corrected__eleEsScaleUp", "PG_internal_quantity_1__eleEsScaleUp", 10.0);
    auto df4 = physicsobject::CutPt(df3, "Electron_pt_corrected__eleEsResoUp", "PG_internal_quantity_1__eleEsResoUp", 10.0);
    auto df5 = physicsobject::CutPt(df4, "Electron_pt_corrected__eleEsScaleDown", "PG_internal_quantity_1__eleEsScaleDown", 10.0);
    auto df6 = physicsobject::CutEta(df5, "Electron_eta", "PG_internal_quantity_2", 2.5);
    auto df7 = physicsobject::CutDxy(df6, "Electron_dxy", "PG_internal_quantity_3", 0.045);
    auto df8 = physicsobject::CutDz(df7, "Electron_dz", "PG_internal_quantity_4", 0.2);
    auto df9 = physicsobject::electron::CutID(df8, "PG_internal_quantity_5", "Electron_mvaFall17V2noIso_WP90");
    auto df10 = physicsobject::electron::CutIsolation(df9, "PG_internal_quantity_6", "Electron_pfRelIso03_all", 0.3);
    auto df11 = physicsobject::CombineMasks(df10, "base_electrons_mask", "PG_internal_quantity_1", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_5", "PG_internal_quantity_6");
    auto df12 = physicsobject::CombineMasks(df11, "base_electrons_mask__eleEsResoDown", "PG_internal_quantity_1__eleEsResoDown", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_5", "PG_internal_quantity_6");
    auto df13 = physicsobject::CombineMasks(df12, "base_electrons_mask__eleEsScaleUp", "PG_internal_quantity_1__eleEsScaleUp", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_5", "PG_internal_quantity_6");
    auto df14 = physicsobject::CombineMasks(df13, "base_electrons_mask__eleEsResoUp", "PG_internal_quantity_1__eleEsResoUp", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_5", "PG_internal_quantity_6");
    auto df15 = physicsobject::CombineMasks(df14, "base_electrons_mask__eleEsScaleDown", "PG_internal_quantity_1__eleEsScaleDown", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_5", "PG_internal_quantity_6");
    return df15;

}
