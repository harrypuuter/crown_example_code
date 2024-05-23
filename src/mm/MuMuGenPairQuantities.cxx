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
ROOT::RDF::RNode MuMuGenPairQuantities_mm (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::buildgenpair(df0, "dileptonpair", "Muon_genPartIdx", "Muon_genPartIdx", "gen_dileptonpair");
    auto df2 = lorentzvectors::build(df1, {"gen_dileptonpair","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1");
    auto df3 = lorentzvectors::build(df2, {"gen_dileptonpair","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2");
    auto df4 = quantities::pt(df3, "gen_pt_1", "gen_p4_1");
    auto df5 = quantities::eta(df4, "gen_eta_1", "gen_p4_1");
    auto df6 = quantities::phi(df5, "gen_phi_1", "gen_p4_1");
    auto df7 = quantities::mass(df6, "gen_mass_1", "gen_p4_1");
    auto df8 = quantities::pdgid(df7, "gen_pdgid_1", 0, "gen_dileptonpair", "GenPart_pdgId");
    auto df9 = quantities::pt(df8, "gen_pt_2", "gen_p4_2");
    auto df10 = quantities::eta(df9, "gen_eta_2", "gen_p4_2");
    auto df11 = quantities::phi(df10, "gen_phi_2", "gen_p4_2");
    auto df12 = quantities::mass(df11, "gen_mass_2", "gen_p4_2");
    auto df13 = quantities::pdgid(df12, "gen_pdgid_2", 1, "gen_dileptonpair", "GenPart_pdgId");
    auto df14 = quantities::m_vis(df13, "gen_m_vis", {"gen_p4_1","gen_p4_2"});
    return df14;

}
