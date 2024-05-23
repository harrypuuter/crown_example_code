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
ROOT::RDF::RNode MTGenDiTauPairQuantities_mt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::buildgenpair(df0, "dileptonpair", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair");
    auto df2 = ditau_pairselection::buildgenpair(df1, "dileptonpair__tauEs3prong1pizeroDown", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong1pizeroDown");
    auto df3 = ditau_pairselection::buildgenpair(df2, "dileptonpair__tauEs1prong0pizeroDown", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong0pizeroDown");
    auto df4 = ditau_pairselection::buildgenpair(df3, "dileptonpair__tauEs3prong1pizeroUp", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong1pizeroUp");
    auto df5 = ditau_pairselection::buildgenpair(df4, "dileptonpair__tauEs1prong1pizeroDown", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong1pizeroDown");
    auto df6 = ditau_pairselection::buildgenpair(df5, "dileptonpair__tauEs1prong1pizeroUp", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong1pizeroUp");
    auto df7 = ditau_pairselection::buildgenpair(df6, "dileptonpair__tauEs1prong0pizeroUp", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong0pizeroUp");
    auto df8 = ditau_pairselection::buildgenpair(df7, "dileptonpair__tauEs3prong0pizeroDown", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong0pizeroDown");
    auto df9 = ditau_pairselection::buildgenpair(df8, "dileptonpair__tauEs3prong0pizeroUp", "Muon_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong0pizeroUp");
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
    auto df73 = quantities::pt(df72, "gen_pt_2", "gen_p4_2");
    auto df74 = quantities::pt(df73, "gen_pt_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df75 = quantities::pt(df74, "gen_pt_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df76 = quantities::pt(df75, "gen_pt_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df77 = quantities::pt(df76, "gen_pt_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df78 = quantities::pt(df77, "gen_pt_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df79 = quantities::pt(df78, "gen_pt_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df80 = quantities::pt(df79, "gen_pt_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df81 = quantities::pt(df80, "gen_pt_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df82 = quantities::eta(df81, "gen_eta_2", "gen_p4_2");
    auto df83 = quantities::eta(df82, "gen_eta_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df84 = quantities::eta(df83, "gen_eta_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df85 = quantities::eta(df84, "gen_eta_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df86 = quantities::eta(df85, "gen_eta_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df87 = quantities::eta(df86, "gen_eta_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df88 = quantities::eta(df87, "gen_eta_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df89 = quantities::eta(df88, "gen_eta_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df90 = quantities::eta(df89, "gen_eta_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df91 = quantities::phi(df90, "gen_phi_2", "gen_p4_2");
    auto df92 = quantities::phi(df91, "gen_phi_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df93 = quantities::phi(df92, "gen_phi_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df94 = quantities::phi(df93, "gen_phi_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df95 = quantities::phi(df94, "gen_phi_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df96 = quantities::phi(df95, "gen_phi_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df97 = quantities::phi(df96, "gen_phi_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df98 = quantities::phi(df97, "gen_phi_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df99 = quantities::phi(df98, "gen_phi_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df100 = quantities::mass(df99, "gen_mass_2", "gen_p4_2");
    auto df101 = quantities::mass(df100, "gen_mass_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df102 = quantities::mass(df101, "gen_mass_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df103 = quantities::mass(df102, "gen_mass_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df104 = quantities::mass(df103, "gen_mass_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df105 = quantities::mass(df104, "gen_mass_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df106 = quantities::mass(df105, "gen_mass_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df107 = quantities::mass(df106, "gen_mass_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df108 = quantities::mass(df107, "gen_mass_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df109 = quantities::pdgid(df108, "gen_pdgid_2", 1, "gen_dileptonpair", "GenPart_pdgId");
    auto df110 = quantities::pdgid(df109, "gen_pdgid_2__tauEs3prong1pizeroDown", 1, "gen_dileptonpair__tauEs3prong1pizeroDown", "GenPart_pdgId");
    auto df111 = quantities::pdgid(df110, "gen_pdgid_2__tauEs1prong0pizeroDown", 1, "gen_dileptonpair__tauEs1prong0pizeroDown", "GenPart_pdgId");
    auto df112 = quantities::pdgid(df111, "gen_pdgid_2__tauEs3prong1pizeroUp", 1, "gen_dileptonpair__tauEs3prong1pizeroUp", "GenPart_pdgId");
    auto df113 = quantities::pdgid(df112, "gen_pdgid_2__tauEs1prong1pizeroDown", 1, "gen_dileptonpair__tauEs1prong1pizeroDown", "GenPart_pdgId");
    auto df114 = quantities::pdgid(df113, "gen_pdgid_2__tauEs1prong1pizeroUp", 1, "gen_dileptonpair__tauEs1prong1pizeroUp", "GenPart_pdgId");
    auto df115 = quantities::pdgid(df114, "gen_pdgid_2__tauEs1prong0pizeroUp", 1, "gen_dileptonpair__tauEs1prong0pizeroUp", "GenPart_pdgId");
    auto df116 = quantities::pdgid(df115, "gen_pdgid_2__tauEs3prong0pizeroDown", 1, "gen_dileptonpair__tauEs3prong0pizeroDown", "GenPart_pdgId");
    auto df117 = quantities::pdgid(df116, "gen_pdgid_2__tauEs3prong0pizeroUp", 1, "gen_dileptonpair__tauEs3prong0pizeroUp", "GenPart_pdgId");
    auto df118 = quantities::tau::matching_genjet_pt(df117, "gen_taujet_pt_2", 1, "dileptonpair", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df119 = quantities::tau::matching_genjet_pt(df118, "gen_taujet_pt_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df120 = quantities::tau::matching_genjet_pt(df119, "gen_taujet_pt_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df121 = quantities::tau::matching_genjet_pt(df120, "gen_taujet_pt_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df122 = quantities::tau::matching_genjet_pt(df121, "gen_taujet_pt_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df123 = quantities::tau::matching_genjet_pt(df122, "gen_taujet_pt_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df124 = quantities::tau::matching_genjet_pt(df123, "gen_taujet_pt_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df125 = quantities::tau::matching_genjet_pt(df124, "gen_taujet_pt_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df126 = quantities::tau::matching_genjet_pt(df125, "gen_taujet_pt_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df127 = quantities::m_vis(df126, "gen_m_vis", {"gen_p4_1","gen_p4_2"});
    auto df128 = quantities::m_vis(df127, "gen_m_vis__tauEs3prong1pizeroDown", {"gen_p4_1__tauEs3prong1pizeroDown","gen_p4_2__tauEs3prong1pizeroDown"});
    auto df129 = quantities::m_vis(df128, "gen_m_vis__tauEs1prong0pizeroDown", {"gen_p4_1__tauEs1prong0pizeroDown","gen_p4_2__tauEs1prong0pizeroDown"});
    auto df130 = quantities::m_vis(df129, "gen_m_vis__tauEs3prong1pizeroUp", {"gen_p4_1__tauEs3prong1pizeroUp","gen_p4_2__tauEs3prong1pizeroUp"});
    auto df131 = quantities::m_vis(df130, "gen_m_vis__tauEs1prong1pizeroDown", {"gen_p4_1__tauEs1prong1pizeroDown","gen_p4_2__tauEs1prong1pizeroDown"});
    auto df132 = quantities::m_vis(df131, "gen_m_vis__tauEs1prong1pizeroUp", {"gen_p4_1__tauEs1prong1pizeroUp","gen_p4_2__tauEs1prong1pizeroUp"});
    auto df133 = quantities::m_vis(df132, "gen_m_vis__tauEs1prong0pizeroUp", {"gen_p4_1__tauEs1prong0pizeroUp","gen_p4_2__tauEs1prong0pizeroUp"});
    auto df134 = quantities::m_vis(df133, "gen_m_vis__tauEs3prong0pizeroDown", {"gen_p4_1__tauEs3prong0pizeroDown","gen_p4_2__tauEs3prong0pizeroDown"});
    auto df135 = quantities::m_vis(df134, "gen_m_vis__tauEs3prong0pizeroUp", {"gen_p4_1__tauEs3prong0pizeroUp","gen_p4_2__tauEs3prong0pizeroUp"});
    return df135;

}
