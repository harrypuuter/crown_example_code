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
ROOT::RDF::RNode GenMatching_tt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = genmatching::tau::hadronicGenTaus(df0, "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_genPartIdxMother");
    auto df2 = genmatching::tau::genmatching(df1, "gen_match_1", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1");
    auto df3 = genmatching::tau::genmatching(df2, "gen_match_1__tauEs3prong1pizeroDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__tauEs3prong1pizeroDown");
    auto df4 = genmatching::tau::genmatching(df3, "gen_match_1__tauEs1prong0pizeroDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__tauEs1prong0pizeroDown");
    auto df5 = genmatching::tau::genmatching(df4, "gen_match_1__tauEs3prong1pizeroUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__tauEs3prong1pizeroUp");
    auto df6 = genmatching::tau::genmatching(df5, "gen_match_1__tauEs1prong1pizeroDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__tauEs1prong1pizeroDown");
    auto df7 = genmatching::tau::genmatching(df6, "gen_match_1__tauEs1prong1pizeroUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__tauEs1prong1pizeroUp");
    auto df8 = genmatching::tau::genmatching(df7, "gen_match_1__tauEs1prong0pizeroUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__tauEs1prong0pizeroUp");
    auto df9 = genmatching::tau::genmatching(df8, "gen_match_1__tauEs3prong0pizeroDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__tauEs3prong0pizeroDown");
    auto df10 = genmatching::tau::genmatching(df9, "gen_match_1__tauEs3prong0pizeroUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_1__tauEs3prong0pizeroUp");
    auto df11 = genmatching::tau::genmatching(df10, "gen_match_2", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2");
    auto df12 = genmatching::tau::genmatching(df11, "gen_match_2__tauEs3prong1pizeroDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__tauEs3prong1pizeroDown");
    auto df13 = genmatching::tau::genmatching(df12, "gen_match_2__tauEs1prong0pizeroDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__tauEs1prong0pizeroDown");
    auto df14 = genmatching::tau::genmatching(df13, "gen_match_2__tauEs3prong1pizeroUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__tauEs3prong1pizeroUp");
    auto df15 = genmatching::tau::genmatching(df14, "gen_match_2__tauEs1prong1pizeroDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__tauEs1prong1pizeroDown");
    auto df16 = genmatching::tau::genmatching(df15, "gen_match_2__tauEs1prong1pizeroUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__tauEs1prong1pizeroUp");
    auto df17 = genmatching::tau::genmatching(df16, "gen_match_2__tauEs1prong0pizeroUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__tauEs1prong0pizeroUp");
    auto df18 = genmatching::tau::genmatching(df17, "gen_match_2__tauEs3prong0pizeroDown", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__tauEs3prong0pizeroDown");
    auto df19 = genmatching::tau::genmatching(df18, "gen_match_2__tauEs3prong0pizeroUp", "hadronic_gen_taus", "GenPart_pdgId", "GenPart_statusFlags", "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "p4_2__tauEs3prong0pizeroUp");
    return df19;

}
