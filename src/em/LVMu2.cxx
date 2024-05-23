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
ROOT::RDF::RNode LVMu2_em (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = lorentzvectors::build(df0, {"dileptonpair","Muon_pt","Muon_eta","Muon_phi","Muon_mass"}, 1, "p4_2");
    auto df2 = lorentzvectors::build(df1, {"dileptonpair__eleEsResoDown","Muon_pt","Muon_eta","Muon_phi","Muon_mass"}, 1, "p4_2__eleEsResoDown");
    auto df3 = lorentzvectors::build(df2, {"dileptonpair__eleEsScaleUp","Muon_pt","Muon_eta","Muon_phi","Muon_mass"}, 1, "p4_2__eleEsScaleUp");
    auto df4 = lorentzvectors::build(df3, {"dileptonpair__eleEsResoUp","Muon_pt","Muon_eta","Muon_phi","Muon_mass"}, 1, "p4_2__eleEsResoUp");
    auto df5 = lorentzvectors::build(df4, {"dileptonpair__eleEsScaleDown","Muon_pt","Muon_eta","Muon_phi","Muon_mass"}, 1, "p4_2__eleEsScaleDown");
    return df5;

}
