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
ROOT::RDF::RNode TTGenDiTauPairQuantities_tt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::buildgenpair(df0, "dileptonpair", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair");
    auto df2 = ditau_pairselection::buildgenpair(df1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong1pizeroDown");
    auto df3 = ditau_pairselection::buildgenpair(df2, "dileptonpair__tauEs1prong0pizeroDown", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong0pizeroDown");
    auto df4 = ditau_pairselection::buildgenpair(df3, "dileptonpair__tauEs3prong1pizeroUp", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong1pizeroUp");
    auto df5 = ditau_pairselection::buildgenpair(df4, "dileptonpair__tauEs1prong1pizeroDown", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong1pizeroDown");
    auto df6 = ditau_pairselection::buildgenpair(df5, "dileptonpair__tauEs1prong1pizeroUp", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong1pizeroUp");
    auto df7 = ditau_pairselection::buildgenpair(df6, "dileptonpair__tauEs1prong0pizeroUp", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong0pizeroUp");
    auto df8 = ditau_pairselection::buildgenpair(df7, "dileptonpair__tauEs3prong0pizeroDown", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong0pizeroDown");
    auto df9 = ditau_pairselection::buildgenpair(df8, "dileptonpair__tauEs3prong0pizeroUp", "Tau_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong0pizeroUp");
    auto df10 = lorentzvectors::build(df9, {"gen_dileptonpair","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1");
    auto df11 = lorentzvectors::build(df10, {"gen_dileptonpair__tauEs3prong1pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs3prong1pizeroDown");
    auto df12 = lorentzvectors::build(df11, {"gen_dileptonpair__tauEs1prong0pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs1prong0pizeroDown");
    auto df13 = lorentzvectors::build(df12, {"gen_dileptonpair__tauEs3prong1pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs3prong1pizeroUp");
    auto df14 = lorentzvectors::build(df13, {"gen_dileptonpair__tauEs1prong1pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs1prong1pizeroDown");
    auto df15 = lorentzvectors::build(df14, {"gen_dileptonpair__tauEs1prong1pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs1prong1pizeroUp");
    auto df16 = lorentzvectors::build(df15, {"gen_dileptonpair__tauEs1prong0pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs1prong0pizeroUp");
    auto df17 = lorentzvectors::build(df16, {"gen_dileptonpair__tauEs3prong0pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs3prong0pizeroDown");
    auto df18 = lorentzvectors::build(df17, {"gen_dileptonpair__tauEs3prong0pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs3prong0pizeroUp");
    auto df19 = lorentzvectors::build(df18, {"gen_dileptonpair","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2");
    auto df20 = lorentzvectors::build(df19, {"gen_dileptonpair__tauEs3prong1pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs3prong1pizeroDown");
    auto df21 = lorentzvectors::build(df20, {"gen_dileptonpair__tauEs1prong0pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs1prong0pizeroDown");
    auto df22 = lorentzvectors::build(df21, {"gen_dileptonpair__tauEs3prong1pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs3prong1pizeroUp");
    auto df23 = lorentzvectors::build(df22, {"gen_dileptonpair__tauEs1prong1pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs1prong1pizeroDown");
    auto df24 = lorentzvectors::build(df23, {"gen_dileptonpair__tauEs1prong1pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs1prong1pizeroUp");
    auto df25 = lorentzvectors::build(df24, {"gen_dileptonpair__tauEs1prong0pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs1prong0pizeroUp");
    auto df26 = lorentzvectors::build(df25, {"gen_dileptonpair__tauEs3prong0pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs3prong0pizeroDown");
    auto df27 = lorentzvectors::build(df26, {"gen_dileptonpair__tauEs3prong0pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs3prong0pizeroUp");
    auto df28 = quantities::pt(df27, "gen_pt_1", "gen_p4_1");
    auto df29 = quantities::pt(df28, "gen_pt_1__tauEs3prong1pizeroDown", "gen_p4_1__tauEs3prong1pizeroDown");
    auto df30 = quantities::pt(df29, "gen_pt_1__tauEs1prong0pizeroDown", "gen_p4_1__tauEs1prong0pizeroDown");
    auto df31 = quantities::pt(df30, "gen_pt_1__tauEs3prong1pizeroUp", "gen_p4_1__tauEs3prong1pizeroUp");
    auto df32 = quantities::pt(df31, "gen_pt_1__tauEs1prong1pizeroDown", "gen_p4_1__tauEs1prong1pizeroDown");
    auto df33 = quantities::pt(df32, "gen_pt_1__tauEs1prong1pizeroUp", "gen_p4_1__tauEs1prong1pizeroUp");
    auto df34 = quantities::pt(df33, "gen_pt_1__tauEs1prong0pizeroUp", "gen_p4_1__tauEs1prong0pizeroUp");
    auto df35 = quantities::pt(df34, "gen_pt_1__tauEs3prong0pizeroDown", "gen_p4_1__tauEs3prong0pizeroDown");
    auto df36 = quantities::pt(df35, "gen_pt_1__tauEs3prong0pizeroUp", "gen_p4_1__tauEs3prong0pizeroUp");
    auto df37 = quantities::eta(df36, "gen_eta_1", "gen_p4_1");
    auto df38 = quantities::eta(df37, "gen_eta_1__tauEs3prong1pizeroDown", "gen_p4_1__tauEs3prong1pizeroDown");
    auto df39 = quantities::eta(df38, "gen_eta_1__tauEs1prong0pizeroDown", "gen_p4_1__tauEs1prong0pizeroDown");
    auto df40 = quantities::eta(df39, "gen_eta_1__tauEs3prong1pizeroUp", "gen_p4_1__tauEs3prong1pizeroUp");
    auto df41 = quantities::eta(df40, "gen_eta_1__tauEs1prong1pizeroDown", "gen_p4_1__tauEs1prong1pizeroDown");
    auto df42 = quantities::eta(df41, "gen_eta_1__tauEs1prong1pizeroUp", "gen_p4_1__tauEs1prong1pizeroUp");
    auto df43 = quantities::eta(df42, "gen_eta_1__tauEs1prong0pizeroUp", "gen_p4_1__tauEs1prong0pizeroUp");
    auto df44 = quantities::eta(df43, "gen_eta_1__tauEs3prong0pizeroDown", "gen_p4_1__tauEs3prong0pizeroDown");
    auto df45 = quantities::eta(df44, "gen_eta_1__tauEs3prong0pizeroUp", "gen_p4_1__tauEs3prong0pizeroUp");
    auto df46 = quantities::phi(df45, "gen_phi_1", "gen_p4_1");
    auto df47 = quantities::phi(df46, "gen_phi_1__tauEs3prong1pizeroDown", "gen_p4_1__tauEs3prong1pizeroDown");
    auto df48 = quantities::phi(df47, "gen_phi_1__tauEs1prong0pizeroDown", "gen_p4_1__tauEs1prong0pizeroDown");
    auto df49 = quantities::phi(df48, "gen_phi_1__tauEs3prong1pizeroUp", "gen_p4_1__tauEs3prong1pizeroUp");
    auto df50 = quantities::phi(df49, "gen_phi_1__tauEs1prong1pizeroDown", "gen_p4_1__tauEs1prong1pizeroDown");
    auto df51 = quantities::phi(df50, "gen_phi_1__tauEs1prong1pizeroUp", "gen_p4_1__tauEs1prong1pizeroUp");
    auto df52 = quantities::phi(df51, "gen_phi_1__tauEs1prong0pizeroUp", "gen_p4_1__tauEs1prong0pizeroUp");
    auto df53 = quantities::phi(df52, "gen_phi_1__tauEs3prong0pizeroDown", "gen_p4_1__tauEs3prong0pizeroDown");
    auto df54 = quantities::phi(df53, "gen_phi_1__tauEs3prong0pizeroUp", "gen_p4_1__tauEs3prong0pizeroUp");
    auto df55 = quantities::mass(df54, "gen_mass_1", "gen_p4_1");
    auto df56 = quantities::mass(df55, "gen_mass_1__tauEs3prong1pizeroDown", "gen_p4_1__tauEs3prong1pizeroDown");
    auto df57 = quantities::mass(df56, "gen_mass_1__tauEs1prong0pizeroDown", "gen_p4_1__tauEs1prong0pizeroDown");
    auto df58 = quantities::mass(df57, "gen_mass_1__tauEs3prong1pizeroUp", "gen_p4_1__tauEs3prong1pizeroUp");
    auto df59 = quantities::mass(df58, "gen_mass_1__tauEs1prong1pizeroDown", "gen_p4_1__tauEs1prong1pizeroDown");
    auto df60 = quantities::mass(df59, "gen_mass_1__tauEs1prong1pizeroUp", "gen_p4_1__tauEs1prong1pizeroUp");
    auto df61 = quantities::mass(df60, "gen_mass_1__tauEs1prong0pizeroUp", "gen_p4_1__tauEs1prong0pizeroUp");
    auto df62 = quantities::mass(df61, "gen_mass_1__tauEs3prong0pizeroDown", "gen_p4_1__tauEs3prong0pizeroDown");
    auto df63 = quantities::mass(df62, "gen_mass_1__tauEs3prong0pizeroUp", "gen_p4_1__tauEs3prong0pizeroUp");
    auto df64 = quantities::pdgid(df63, "gen_pdgid_1", 0, "gen_dileptonpair", "GenPart_pdgId");
    auto df65 = quantities::pdgid(df64, "gen_pdgid_1__tauEs3prong1pizeroDown", 0, "gen_dileptonpair__tauEs3prong1pizeroDown", "GenPart_pdgId");
    auto df66 = quantities::pdgid(df65, "gen_pdgid_1__tauEs1prong0pizeroDown", 0, "gen_dileptonpair__tauEs1prong0pizeroDown", "GenPart_pdgId");
    auto df67 = quantities::pdgid(df66, "gen_pdgid_1__tauEs3prong1pizeroUp", 0, "gen_dileptonpair__tauEs3prong1pizeroUp", "GenPart_pdgId");
    auto df68 = quantities::pdgid(df67, "gen_pdgid_1__tauEs1prong1pizeroDown", 0, "gen_dileptonpair__tauEs1prong1pizeroDown", "GenPart_pdgId");
    auto df69 = quantities::pdgid(df68, "gen_pdgid_1__tauEs1prong1pizeroUp", 0, "gen_dileptonpair__tauEs1prong1pizeroUp", "GenPart_pdgId");
    auto df70 = quantities::pdgid(df69, "gen_pdgid_1__tauEs1prong0pizeroUp", 0, "gen_dileptonpair__tauEs1prong0pizeroUp", "GenPart_pdgId");
    auto df71 = quantities::pdgid(df70, "gen_pdgid_1__tauEs3prong0pizeroDown", 0, "gen_dileptonpair__tauEs3prong0pizeroDown", "GenPart_pdgId");
    auto df72 = quantities::pdgid(df71, "gen_pdgid_1__tauEs3prong0pizeroUp", 0, "gen_dileptonpair__tauEs3prong0pizeroUp", "GenPart_pdgId");
    auto df73 = quantities::tau::matching_genjet_pt(df72, "gen_taujet_pt_1", 0, "dileptonpair", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df74 = quantities::tau::matching_genjet_pt(df73, "gen_taujet_pt_1__tauEs3prong1pizeroDown", 0, "dileptonpair__tauEs3prong1pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df75 = quantities::tau::matching_genjet_pt(df74, "gen_taujet_pt_1__tauEs1prong0pizeroDown", 0, "dileptonpair__tauEs1prong0pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df76 = quantities::tau::matching_genjet_pt(df75, "gen_taujet_pt_1__tauEs3prong1pizeroUp", 0, "dileptonpair__tauEs3prong1pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df77 = quantities::tau::matching_genjet_pt(df76, "gen_taujet_pt_1__tauEs1prong1pizeroDown", 0, "dileptonpair__tauEs1prong1pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df78 = quantities::tau::matching_genjet_pt(df77, "gen_taujet_pt_1__tauEs1prong1pizeroUp", 0, "dileptonpair__tauEs1prong1pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df79 = quantities::tau::matching_genjet_pt(df78, "gen_taujet_pt_1__tauEs1prong0pizeroUp", 0, "dileptonpair__tauEs1prong0pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df80 = quantities::tau::matching_genjet_pt(df79, "gen_taujet_pt_1__tauEs3prong0pizeroDown", 0, "dileptonpair__tauEs3prong0pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df81 = quantities::tau::matching_genjet_pt(df80, "gen_taujet_pt_1__tauEs3prong0pizeroUp", 0, "dileptonpair__tauEs3prong0pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df82 = quantities::pt(df81, "gen_pt_2", "gen_p4_2");
    auto df83 = quantities::pt(df82, "gen_pt_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df84 = quantities::pt(df83, "gen_pt_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df85 = quantities::pt(df84, "gen_pt_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df86 = quantities::pt(df85, "gen_pt_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df87 = quantities::pt(df86, "gen_pt_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df88 = quantities::pt(df87, "gen_pt_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df89 = quantities::pt(df88, "gen_pt_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df90 = quantities::pt(df89, "gen_pt_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df91 = quantities::eta(df90, "gen_eta_2", "gen_p4_2");
    auto df92 = quantities::eta(df91, "gen_eta_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df93 = quantities::eta(df92, "gen_eta_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df94 = quantities::eta(df93, "gen_eta_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df95 = quantities::eta(df94, "gen_eta_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df96 = quantities::eta(df95, "gen_eta_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df97 = quantities::eta(df96, "gen_eta_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df98 = quantities::eta(df97, "gen_eta_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df99 = quantities::eta(df98, "gen_eta_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df100 = quantities::phi(df99, "gen_phi_2", "gen_p4_2");
    auto df101 = quantities::phi(df100, "gen_phi_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df102 = quantities::phi(df101, "gen_phi_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df103 = quantities::phi(df102, "gen_phi_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df104 = quantities::phi(df103, "gen_phi_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df105 = quantities::phi(df104, "gen_phi_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df106 = quantities::phi(df105, "gen_phi_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df107 = quantities::phi(df106, "gen_phi_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df108 = quantities::phi(df107, "gen_phi_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df109 = quantities::mass(df108, "gen_mass_2", "gen_p4_2");
    auto df110 = quantities::mass(df109, "gen_mass_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df111 = quantities::mass(df110, "gen_mass_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df112 = quantities::mass(df111, "gen_mass_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df113 = quantities::mass(df112, "gen_mass_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df114 = quantities::mass(df113, "gen_mass_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df115 = quantities::mass(df114, "gen_mass_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df116 = quantities::mass(df115, "gen_mass_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df117 = quantities::mass(df116, "gen_mass_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df118 = quantities::pdgid(df117, "gen_pdgid_2", 1, "gen_dileptonpair", "GenPart_pdgId");
    auto df119 = quantities::pdgid(df118, "gen_pdgid_2__tauEs3prong1pizeroDown", 1, "gen_dileptonpair__tauEs3prong1pizeroDown", "GenPart_pdgId");
    auto df120 = quantities::pdgid(df119, "gen_pdgid_2__tauEs1prong0pizeroDown", 1, "gen_dileptonpair__tauEs1prong0pizeroDown", "GenPart_pdgId");
    auto df121 = quantities::pdgid(df120, "gen_pdgid_2__tauEs3prong1pizeroUp", 1, "gen_dileptonpair__tauEs3prong1pizeroUp", "GenPart_pdgId");
    auto df122 = quantities::pdgid(df121, "gen_pdgid_2__tauEs1prong1pizeroDown", 1, "gen_dileptonpair__tauEs1prong1pizeroDown", "GenPart_pdgId");
    auto df123 = quantities::pdgid(df122, "gen_pdgid_2__tauEs1prong1pizeroUp", 1, "gen_dileptonpair__tauEs1prong1pizeroUp", "GenPart_pdgId");
    auto df124 = quantities::pdgid(df123, "gen_pdgid_2__tauEs1prong0pizeroUp", 1, "gen_dileptonpair__tauEs1prong0pizeroUp", "GenPart_pdgId");
    auto df125 = quantities::pdgid(df124, "gen_pdgid_2__tauEs3prong0pizeroDown", 1, "gen_dileptonpair__tauEs3prong0pizeroDown", "GenPart_pdgId");
    auto df126 = quantities::pdgid(df125, "gen_pdgid_2__tauEs3prong0pizeroUp", 1, "gen_dileptonpair__tauEs3prong0pizeroUp", "GenPart_pdgId");
    auto df127 = quantities::tau::matching_genjet_pt(df126, "gen_taujet_pt_2", 1, "dileptonpair", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df128 = quantities::tau::matching_genjet_pt(df127, "gen_taujet_pt_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df129 = quantities::tau::matching_genjet_pt(df128, "gen_taujet_pt_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df130 = quantities::tau::matching_genjet_pt(df129, "gen_taujet_pt_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df131 = quantities::tau::matching_genjet_pt(df130, "gen_taujet_pt_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df132 = quantities::tau::matching_genjet_pt(df131, "gen_taujet_pt_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df133 = quantities::tau::matching_genjet_pt(df132, "gen_taujet_pt_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df134 = quantities::tau::matching_genjet_pt(df133, "gen_taujet_pt_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df135 = quantities::tau::matching_genjet_pt(df134, "gen_taujet_pt_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df136 = quantities::m_vis(df135, "gen_m_vis", {"gen_p4_1","gen_p4_2"});
    auto df137 = quantities::m_vis(df136, "gen_m_vis__tauEs3prong1pizeroDown", {"gen_p4_1__tauEs3prong1pizeroDown","gen_p4_2__tauEs3prong1pizeroDown"});
    auto df138 = quantities::m_vis(df137, "gen_m_vis__tauEs1prong0pizeroDown", {"gen_p4_1__tauEs1prong0pizeroDown","gen_p4_2__tauEs1prong0pizeroDown"});
    auto df139 = quantities::m_vis(df138, "gen_m_vis__tauEs3prong1pizeroUp", {"gen_p4_1__tauEs3prong1pizeroUp","gen_p4_2__tauEs3prong1pizeroUp"});
    auto df140 = quantities::m_vis(df139, "gen_m_vis__tauEs1prong1pizeroDown", {"gen_p4_1__tauEs1prong1pizeroDown","gen_p4_2__tauEs1prong1pizeroDown"});
    auto df141 = quantities::m_vis(df140, "gen_m_vis__tauEs1prong1pizeroUp", {"gen_p4_1__tauEs1prong1pizeroUp","gen_p4_2__tauEs1prong1pizeroUp"});
    auto df142 = quantities::m_vis(df141, "gen_m_vis__tauEs1prong0pizeroUp", {"gen_p4_1__tauEs1prong0pizeroUp","gen_p4_2__tauEs1prong0pizeroUp"});
    auto df143 = quantities::m_vis(df142, "gen_m_vis__tauEs3prong0pizeroDown", {"gen_p4_1__tauEs3prong0pizeroDown","gen_p4_2__tauEs3prong0pizeroDown"});
    auto df144 = quantities::m_vis(df143, "gen_m_vis__tauEs3prong0pizeroUp", {"gen_p4_1__tauEs3prong0pizeroUp","gen_p4_2__tauEs3prong0pizeroUp"});
    return df144;

}
