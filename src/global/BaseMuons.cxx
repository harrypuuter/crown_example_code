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
ROOT::RDF::RNode BaseMuons_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::CutPt(df0, "Muon_pt", "PG_internal_quantity_13", 10.0);
    auto df2 = physicsobject::CutEta(df1, "Muon_eta", "PG_internal_quantity_14", 2.4);
    auto df3 = physicsobject::CutDxy(df2, "Muon_dxy", "PG_internal_quantity_15", 0.045);
    auto df4 = physicsobject::CutDz(df3, "Muon_dz", "PG_internal_quantity_16", 0.2);
    auto df5 = physicsobject::muon::CutID(df4, "PG_internal_quantity_17", "Muon_mediumId");
    auto df6 = physicsobject::muon::CutIsolation(df5, "PG_internal_quantity_18", "Muon_pfRelIso04_all", 0.3);
    auto df7 = physicsobject::CombineMasks(df6, "base_muons_mask", "PG_internal_quantity_13", "PG_internal_quantity_14", "PG_internal_quantity_15", "PG_internal_quantity_16", "PG_internal_quantity_17", "PG_internal_quantity_18");
    return df7;

}
