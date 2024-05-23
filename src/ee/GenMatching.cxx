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
ROOT::RDF::RNode GenMatching_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = genmatching::tau::hadronicGenTaus(df0, "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_genPartIdxMother");
    auto df2 = genmatching::tau::genmatching(df1, "gen_match_1", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1");
    auto df3 = genmatching::tau::genmatching(df2, "gen_match_1__eleEsResoDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__eleEsResoDown");
    auto df4 = genmatching::tau::genmatching(df3, "gen_match_1__eleEsScaleUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__eleEsScaleUp");
    auto df5 = genmatching::tau::genmatching(df4, "gen_match_1__eleEsResoUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__eleEsResoUp");
    auto df6 = genmatching::tau::genmatching(df5, "gen_match_1__eleEsScaleDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__eleEsScaleDown");
    auto df7 = genmatching::tau::genmatching(df6, "gen_match_2", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2");
    auto df8 = genmatching::tau::genmatching(df7, "gen_match_2__eleEsResoDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__eleEsResoDown");
    auto df9 = genmatching::tau::genmatching(df8, "gen_match_2__eleEsScaleUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__eleEsScaleUp");
    auto df10 = genmatching::tau::genmatching(df9, "gen_match_2__eleEsResoUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__eleEsResoUp");
    auto df11 = genmatching::tau::genmatching(df10, "gen_match_2__eleEsScaleDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__eleEsScaleDown");
    return df11;

}
