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
ROOT::RDF::RNode ETGenDiTauPairQuantities_et (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::buildgenpair(df0, "dileptonpair", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair");
    auto df2 = ditau_pairselection::buildgenpair(df1, "dileptonpair__tauEs3prong1pizeroDown", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong1pizeroDown");
    auto df3 = ditau_pairselection::buildgenpair(df2, "dileptonpair__eleEsResoUp", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__eleEsResoUp");
    auto df4 = ditau_pairselection::buildgenpair(df3, "dileptonpair__tauEs3prong0pizeroDown", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong0pizeroDown");
    auto df5 = ditau_pairselection::buildgenpair(df4, "dileptonpair__tauEs1prong0pizeroDown", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong0pizeroDown");
    auto df6 = ditau_pairselection::buildgenpair(df5, "dileptonpair__tauEs3prong1pizeroUp", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong1pizeroUp");
    auto df7 = ditau_pairselection::buildgenpair(df6, "dileptonpair__tauEs1prong1pizeroDown", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong1pizeroDown");
    auto df8 = ditau_pairselection::buildgenpair(df7, "dileptonpair__tauEs1prong1pizeroUp", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong1pizeroUp");
    auto df9 = ditau_pairselection::buildgenpair(df8, "dileptonpair__eleEsResoDown", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__eleEsResoDown");
    auto df10 = ditau_pairselection::buildgenpair(df9, "dileptonpair__tauEs1prong0pizeroUp", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs1prong0pizeroUp");
    auto df11 = ditau_pairselection::buildgenpair(df10, "dileptonpair__eleEsScaleDown", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__eleEsScaleDown");
    auto df12 = ditau_pairselection::buildgenpair(df11, "dileptonpair__tauEs3prong0pizeroUp", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__tauEs3prong0pizeroUp");
    auto df13 = ditau_pairselection::buildgenpair(df12, "dileptonpair__eleEsScaleUp", "Electron_genPartIdx", "Tau_genPartIdx", "gen_dileptonpair__eleEsScaleUp");
    auto df14 = lorentzvectors::build(df13, {"gen_dileptonpair","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1");
    auto df15 = lorentzvectors::build(df14, {"gen_dileptonpair__tauEs3prong1pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs3prong1pizeroDown");
    auto df16 = lorentzvectors::build(df15, {"gen_dileptonpair__eleEsResoUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__eleEsResoUp");
    auto df17 = lorentzvectors::build(df16, {"gen_dileptonpair__tauEs3prong0pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs3prong0pizeroDown");
    auto df18 = lorentzvectors::build(df17, {"gen_dileptonpair__tauEs1prong0pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs1prong0pizeroDown");
    auto df19 = lorentzvectors::build(df18, {"gen_dileptonpair__tauEs3prong1pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs3prong1pizeroUp");
    auto df20 = lorentzvectors::build(df19, {"gen_dileptonpair__tauEs1prong1pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs1prong1pizeroDown");
    auto df21 = lorentzvectors::build(df20, {"gen_dileptonpair__tauEs1prong1pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs1prong1pizeroUp");
    auto df22 = lorentzvectors::build(df21, {"gen_dileptonpair__eleEsResoDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__eleEsResoDown");
    auto df23 = lorentzvectors::build(df22, {"gen_dileptonpair__tauEs1prong0pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs1prong0pizeroUp");
    auto df24 = lorentzvectors::build(df23, {"gen_dileptonpair__eleEsScaleDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__eleEsScaleDown");
    auto df25 = lorentzvectors::build(df24, {"gen_dileptonpair__tauEs3prong0pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__tauEs3prong0pizeroUp");
    auto df26 = lorentzvectors::build(df25, {"gen_dileptonpair__eleEsScaleUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__eleEsScaleUp");
    auto df27 = lorentzvectors::build(df26, {"gen_dileptonpair","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2");
    auto df28 = lorentzvectors::build(df27, {"gen_dileptonpair__tauEs3prong1pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs3prong1pizeroDown");
    auto df29 = lorentzvectors::build(df28, {"gen_dileptonpair__eleEsResoUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__eleEsResoUp");
    auto df30 = lorentzvectors::build(df29, {"gen_dileptonpair__tauEs3prong0pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs3prong0pizeroDown");
    auto df31 = lorentzvectors::build(df30, {"gen_dileptonpair__tauEs1prong0pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs1prong0pizeroDown");
    auto df32 = lorentzvectors::build(df31, {"gen_dileptonpair__tauEs3prong1pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs3prong1pizeroUp");
    auto df33 = lorentzvectors::build(df32, {"gen_dileptonpair__tauEs1prong1pizeroDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs1prong1pizeroDown");
    auto df34 = lorentzvectors::build(df33, {"gen_dileptonpair__tauEs1prong1pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs1prong1pizeroUp");
    auto df35 = lorentzvectors::build(df34, {"gen_dileptonpair__eleEsResoDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__eleEsResoDown");
    auto df36 = lorentzvectors::build(df35, {"gen_dileptonpair__tauEs1prong0pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs1prong0pizeroUp");
    auto df37 = lorentzvectors::build(df36, {"gen_dileptonpair__eleEsScaleDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__eleEsScaleDown");
    auto df38 = lorentzvectors::build(df37, {"gen_dileptonpair__tauEs3prong0pizeroUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__tauEs3prong0pizeroUp");
    auto df39 = lorentzvectors::build(df38, {"gen_dileptonpair__eleEsScaleUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__eleEsScaleUp");
    auto df40 = quantities::pt(df39, "gen_pt_1", "gen_p4_1");
    auto df41 = quantities::pt(df40, "gen_pt_1__tauEs3prong1pizeroDown", "gen_p4_1__tauEs3prong1pizeroDown");
    auto df42 = quantities::pt(df41, "gen_pt_1__eleEsResoUp", "gen_p4_1__eleEsResoUp");
    auto df43 = quantities::pt(df42, "gen_pt_1__tauEs3prong0pizeroDown", "gen_p4_1__tauEs3prong0pizeroDown");
    auto df44 = quantities::pt(df43, "gen_pt_1__tauEs1prong0pizeroDown", "gen_p4_1__tauEs1prong0pizeroDown");
    auto df45 = quantities::pt(df44, "gen_pt_1__tauEs3prong1pizeroUp", "gen_p4_1__tauEs3prong1pizeroUp");
    auto df46 = quantities::pt(df45, "gen_pt_1__tauEs1prong1pizeroDown", "gen_p4_1__tauEs1prong1pizeroDown");
    auto df47 = quantities::pt(df46, "gen_pt_1__tauEs1prong1pizeroUp", "gen_p4_1__tauEs1prong1pizeroUp");
    auto df48 = quantities::pt(df47, "gen_pt_1__eleEsResoDown", "gen_p4_1__eleEsResoDown");
    auto df49 = quantities::pt(df48, "gen_pt_1__tauEs1prong0pizeroUp", "gen_p4_1__tauEs1prong0pizeroUp");
    auto df50 = quantities::pt(df49, "gen_pt_1__eleEsScaleDown", "gen_p4_1__eleEsScaleDown");
    auto df51 = quantities::pt(df50, "gen_pt_1__tauEs3prong0pizeroUp", "gen_p4_1__tauEs3prong0pizeroUp");
    auto df52 = quantities::pt(df51, "gen_pt_1__eleEsScaleUp", "gen_p4_1__eleEsScaleUp");
    auto df53 = quantities::eta(df52, "gen_eta_1", "gen_p4_1");
    auto df54 = quantities::eta(df53, "gen_eta_1__tauEs3prong1pizeroDown", "gen_p4_1__tauEs3prong1pizeroDown");
    auto df55 = quantities::eta(df54, "gen_eta_1__eleEsResoUp", "gen_p4_1__eleEsResoUp");
    auto df56 = quantities::eta(df55, "gen_eta_1__tauEs3prong0pizeroDown", "gen_p4_1__tauEs3prong0pizeroDown");
    auto df57 = quantities::eta(df56, "gen_eta_1__tauEs1prong0pizeroDown", "gen_p4_1__tauEs1prong0pizeroDown");
    auto df58 = quantities::eta(df57, "gen_eta_1__tauEs3prong1pizeroUp", "gen_p4_1__tauEs3prong1pizeroUp");
    auto df59 = quantities::eta(df58, "gen_eta_1__tauEs1prong1pizeroDown", "gen_p4_1__tauEs1prong1pizeroDown");
    auto df60 = quantities::eta(df59, "gen_eta_1__tauEs1prong1pizeroUp", "gen_p4_1__tauEs1prong1pizeroUp");
    auto df61 = quantities::eta(df60, "gen_eta_1__eleEsResoDown", "gen_p4_1__eleEsResoDown");
    auto df62 = quantities::eta(df61, "gen_eta_1__tauEs1prong0pizeroUp", "gen_p4_1__tauEs1prong0pizeroUp");
    auto df63 = quantities::eta(df62, "gen_eta_1__eleEsScaleDown", "gen_p4_1__eleEsScaleDown");
    auto df64 = quantities::eta(df63, "gen_eta_1__tauEs3prong0pizeroUp", "gen_p4_1__tauEs3prong0pizeroUp");
    auto df65 = quantities::eta(df64, "gen_eta_1__eleEsScaleUp", "gen_p4_1__eleEsScaleUp");
    auto df66 = quantities::phi(df65, "gen_phi_1", "gen_p4_1");
    auto df67 = quantities::phi(df66, "gen_phi_1__tauEs3prong1pizeroDown", "gen_p4_1__tauEs3prong1pizeroDown");
    auto df68 = quantities::phi(df67, "gen_phi_1__eleEsResoUp", "gen_p4_1__eleEsResoUp");
    auto df69 = quantities::phi(df68, "gen_phi_1__tauEs3prong0pizeroDown", "gen_p4_1__tauEs3prong0pizeroDown");
    auto df70 = quantities::phi(df69, "gen_phi_1__tauEs1prong0pizeroDown", "gen_p4_1__tauEs1prong0pizeroDown");
    auto df71 = quantities::phi(df70, "gen_phi_1__tauEs3prong1pizeroUp", "gen_p4_1__tauEs3prong1pizeroUp");
    auto df72 = quantities::phi(df71, "gen_phi_1__tauEs1prong1pizeroDown", "gen_p4_1__tauEs1prong1pizeroDown");
    auto df73 = quantities::phi(df72, "gen_phi_1__tauEs1prong1pizeroUp", "gen_p4_1__tauEs1prong1pizeroUp");
    auto df74 = quantities::phi(df73, "gen_phi_1__eleEsResoDown", "gen_p4_1__eleEsResoDown");
    auto df75 = quantities::phi(df74, "gen_phi_1__tauEs1prong0pizeroUp", "gen_p4_1__tauEs1prong0pizeroUp");
    auto df76 = quantities::phi(df75, "gen_phi_1__eleEsScaleDown", "gen_p4_1__eleEsScaleDown");
    auto df77 = quantities::phi(df76, "gen_phi_1__tauEs3prong0pizeroUp", "gen_p4_1__tauEs3prong0pizeroUp");
    auto df78 = quantities::phi(df77, "gen_phi_1__eleEsScaleUp", "gen_p4_1__eleEsScaleUp");
    auto df79 = quantities::mass(df78, "gen_mass_1", "gen_p4_1");
    auto df80 = quantities::mass(df79, "gen_mass_1__tauEs3prong1pizeroDown", "gen_p4_1__tauEs3prong1pizeroDown");
    auto df81 = quantities::mass(df80, "gen_mass_1__eleEsResoUp", "gen_p4_1__eleEsResoUp");
    auto df82 = quantities::mass(df81, "gen_mass_1__tauEs3prong0pizeroDown", "gen_p4_1__tauEs3prong0pizeroDown");
    auto df83 = quantities::mass(df82, "gen_mass_1__tauEs1prong0pizeroDown", "gen_p4_1__tauEs1prong0pizeroDown");
    auto df84 = quantities::mass(df83, "gen_mass_1__tauEs3prong1pizeroUp", "gen_p4_1__tauEs3prong1pizeroUp");
    auto df85 = quantities::mass(df84, "gen_mass_1__tauEs1prong1pizeroDown", "gen_p4_1__tauEs1prong1pizeroDown");
    auto df86 = quantities::mass(df85, "gen_mass_1__tauEs1prong1pizeroUp", "gen_p4_1__tauEs1prong1pizeroUp");
    auto df87 = quantities::mass(df86, "gen_mass_1__eleEsResoDown", "gen_p4_1__eleEsResoDown");
    auto df88 = quantities::mass(df87, "gen_mass_1__tauEs1prong0pizeroUp", "gen_p4_1__tauEs1prong0pizeroUp");
    auto df89 = quantities::mass(df88, "gen_mass_1__eleEsScaleDown", "gen_p4_1__eleEsScaleDown");
    auto df90 = quantities::mass(df89, "gen_mass_1__tauEs3prong0pizeroUp", "gen_p4_1__tauEs3prong0pizeroUp");
    auto df91 = quantities::mass(df90, "gen_mass_1__eleEsScaleUp", "gen_p4_1__eleEsScaleUp");
    auto df92 = quantities::pdgid(df91, "gen_pdgid_1", 0, "gen_dileptonpair", "GenPart_pdgId");
    auto df93 = quantities::pdgid(df92, "gen_pdgid_1__tauEs3prong1pizeroDown", 0, "gen_dileptonpair__tauEs3prong1pizeroDown", "GenPart_pdgId");
    auto df94 = quantities::pdgid(df93, "gen_pdgid_1__eleEsResoUp", 0, "gen_dileptonpair__eleEsResoUp", "GenPart_pdgId");
    auto df95 = quantities::pdgid(df94, "gen_pdgid_1__tauEs3prong0pizeroDown", 0, "gen_dileptonpair__tauEs3prong0pizeroDown", "GenPart_pdgId");
    auto df96 = quantities::pdgid(df95, "gen_pdgid_1__tauEs1prong0pizeroDown", 0, "gen_dileptonpair__tauEs1prong0pizeroDown", "GenPart_pdgId");
    auto df97 = quantities::pdgid(df96, "gen_pdgid_1__tauEs3prong1pizeroUp", 0, "gen_dileptonpair__tauEs3prong1pizeroUp", "GenPart_pdgId");
    auto df98 = quantities::pdgid(df97, "gen_pdgid_1__tauEs1prong1pizeroDown", 0, "gen_dileptonpair__tauEs1prong1pizeroDown", "GenPart_pdgId");
    auto df99 = quantities::pdgid(df98, "gen_pdgid_1__tauEs1prong1pizeroUp", 0, "gen_dileptonpair__tauEs1prong1pizeroUp", "GenPart_pdgId");
    auto df100 = quantities::pdgid(df99, "gen_pdgid_1__eleEsResoDown", 0, "gen_dileptonpair__eleEsResoDown", "GenPart_pdgId");
    auto df101 = quantities::pdgid(df100, "gen_pdgid_1__tauEs1prong0pizeroUp", 0, "gen_dileptonpair__tauEs1prong0pizeroUp", "GenPart_pdgId");
    auto df102 = quantities::pdgid(df101, "gen_pdgid_1__eleEsScaleDown", 0, "gen_dileptonpair__eleEsScaleDown", "GenPart_pdgId");
    auto df103 = quantities::pdgid(df102, "gen_pdgid_1__tauEs3prong0pizeroUp", 0, "gen_dileptonpair__tauEs3prong0pizeroUp", "GenPart_pdgId");
    auto df104 = quantities::pdgid(df103, "gen_pdgid_1__eleEsScaleUp", 0, "gen_dileptonpair__eleEsScaleUp", "GenPart_pdgId");
    auto df105 = quantities::pt(df104, "gen_pt_2", "gen_p4_2");
    auto df106 = quantities::pt(df105, "gen_pt_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df107 = quantities::pt(df106, "gen_pt_2__eleEsResoUp", "gen_p4_2__eleEsResoUp");
    auto df108 = quantities::pt(df107, "gen_pt_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df109 = quantities::pt(df108, "gen_pt_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df110 = quantities::pt(df109, "gen_pt_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df111 = quantities::pt(df110, "gen_pt_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df112 = quantities::pt(df111, "gen_pt_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df113 = quantities::pt(df112, "gen_pt_2__eleEsResoDown", "gen_p4_2__eleEsResoDown");
    auto df114 = quantities::pt(df113, "gen_pt_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df115 = quantities::pt(df114, "gen_pt_2__eleEsScaleDown", "gen_p4_2__eleEsScaleDown");
    auto df116 = quantities::pt(df115, "gen_pt_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df117 = quantities::pt(df116, "gen_pt_2__eleEsScaleUp", "gen_p4_2__eleEsScaleUp");
    auto df118 = quantities::eta(df117, "gen_eta_2", "gen_p4_2");
    auto df119 = quantities::eta(df118, "gen_eta_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df120 = quantities::eta(df119, "gen_eta_2__eleEsResoUp", "gen_p4_2__eleEsResoUp");
    auto df121 = quantities::eta(df120, "gen_eta_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df122 = quantities::eta(df121, "gen_eta_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df123 = quantities::eta(df122, "gen_eta_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df124 = quantities::eta(df123, "gen_eta_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df125 = quantities::eta(df124, "gen_eta_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df126 = quantities::eta(df125, "gen_eta_2__eleEsResoDown", "gen_p4_2__eleEsResoDown");
    auto df127 = quantities::eta(df126, "gen_eta_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df128 = quantities::eta(df127, "gen_eta_2__eleEsScaleDown", "gen_p4_2__eleEsScaleDown");
    auto df129 = quantities::eta(df128, "gen_eta_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df130 = quantities::eta(df129, "gen_eta_2__eleEsScaleUp", "gen_p4_2__eleEsScaleUp");
    auto df131 = quantities::phi(df130, "gen_phi_2", "gen_p4_2");
    auto df132 = quantities::phi(df131, "gen_phi_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df133 = quantities::phi(df132, "gen_phi_2__eleEsResoUp", "gen_p4_2__eleEsResoUp");
    auto df134 = quantities::phi(df133, "gen_phi_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df135 = quantities::phi(df134, "gen_phi_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df136 = quantities::phi(df135, "gen_phi_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df137 = quantities::phi(df136, "gen_phi_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df138 = quantities::phi(df137, "gen_phi_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df139 = quantities::phi(df138, "gen_phi_2__eleEsResoDown", "gen_p4_2__eleEsResoDown");
    auto df140 = quantities::phi(df139, "gen_phi_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df141 = quantities::phi(df140, "gen_phi_2__eleEsScaleDown", "gen_p4_2__eleEsScaleDown");
    auto df142 = quantities::phi(df141, "gen_phi_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df143 = quantities::phi(df142, "gen_phi_2__eleEsScaleUp", "gen_p4_2__eleEsScaleUp");
    auto df144 = quantities::mass(df143, "gen_mass_2", "gen_p4_2");
    auto df145 = quantities::mass(df144, "gen_mass_2__tauEs3prong1pizeroDown", "gen_p4_2__tauEs3prong1pizeroDown");
    auto df146 = quantities::mass(df145, "gen_mass_2__eleEsResoUp", "gen_p4_2__eleEsResoUp");
    auto df147 = quantities::mass(df146, "gen_mass_2__tauEs3prong0pizeroDown", "gen_p4_2__tauEs3prong0pizeroDown");
    auto df148 = quantities::mass(df147, "gen_mass_2__tauEs1prong0pizeroDown", "gen_p4_2__tauEs1prong0pizeroDown");
    auto df149 = quantities::mass(df148, "gen_mass_2__tauEs3prong1pizeroUp", "gen_p4_2__tauEs3prong1pizeroUp");
    auto df150 = quantities::mass(df149, "gen_mass_2__tauEs1prong1pizeroDown", "gen_p4_2__tauEs1prong1pizeroDown");
    auto df151 = quantities::mass(df150, "gen_mass_2__tauEs1prong1pizeroUp", "gen_p4_2__tauEs1prong1pizeroUp");
    auto df152 = quantities::mass(df151, "gen_mass_2__eleEsResoDown", "gen_p4_2__eleEsResoDown");
    auto df153 = quantities::mass(df152, "gen_mass_2__tauEs1prong0pizeroUp", "gen_p4_2__tauEs1prong0pizeroUp");
    auto df154 = quantities::mass(df153, "gen_mass_2__eleEsScaleDown", "gen_p4_2__eleEsScaleDown");
    auto df155 = quantities::mass(df154, "gen_mass_2__tauEs3prong0pizeroUp", "gen_p4_2__tauEs3prong0pizeroUp");
    auto df156 = quantities::mass(df155, "gen_mass_2__eleEsScaleUp", "gen_p4_2__eleEsScaleUp");
    auto df157 = quantities::pdgid(df156, "gen_pdgid_2", 1, "gen_dileptonpair", "GenPart_pdgId");
    auto df158 = quantities::pdgid(df157, "gen_pdgid_2__tauEs3prong1pizeroDown", 1, "gen_dileptonpair__tauEs3prong1pizeroDown", "GenPart_pdgId");
    auto df159 = quantities::pdgid(df158, "gen_pdgid_2__eleEsResoUp", 1, "gen_dileptonpair__eleEsResoUp", "GenPart_pdgId");
    auto df160 = quantities::pdgid(df159, "gen_pdgid_2__tauEs3prong0pizeroDown", 1, "gen_dileptonpair__tauEs3prong0pizeroDown", "GenPart_pdgId");
    auto df161 = quantities::pdgid(df160, "gen_pdgid_2__tauEs1prong0pizeroDown", 1, "gen_dileptonpair__tauEs1prong0pizeroDown", "GenPart_pdgId");
    auto df162 = quantities::pdgid(df161, "gen_pdgid_2__tauEs3prong1pizeroUp", 1, "gen_dileptonpair__tauEs3prong1pizeroUp", "GenPart_pdgId");
    auto df163 = quantities::pdgid(df162, "gen_pdgid_2__tauEs1prong1pizeroDown", 1, "gen_dileptonpair__tauEs1prong1pizeroDown", "GenPart_pdgId");
    auto df164 = quantities::pdgid(df163, "gen_pdgid_2__tauEs1prong1pizeroUp", 1, "gen_dileptonpair__tauEs1prong1pizeroUp", "GenPart_pdgId");
    auto df165 = quantities::pdgid(df164, "gen_pdgid_2__eleEsResoDown", 1, "gen_dileptonpair__eleEsResoDown", "GenPart_pdgId");
    auto df166 = quantities::pdgid(df165, "gen_pdgid_2__tauEs1prong0pizeroUp", 1, "gen_dileptonpair__tauEs1prong0pizeroUp", "GenPart_pdgId");
    auto df167 = quantities::pdgid(df166, "gen_pdgid_2__eleEsScaleDown", 1, "gen_dileptonpair__eleEsScaleDown", "GenPart_pdgId");
    auto df168 = quantities::pdgid(df167, "gen_pdgid_2__tauEs3prong0pizeroUp", 1, "gen_dileptonpair__tauEs3prong0pizeroUp", "GenPart_pdgId");
    auto df169 = quantities::pdgid(df168, "gen_pdgid_2__eleEsScaleUp", 1, "gen_dileptonpair__eleEsScaleUp", "GenPart_pdgId");
    auto df170 = quantities::tau::matching_genjet_pt(df169, "gen_taujet_pt_2", 1, "dileptonpair", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df171 = quantities::tau::matching_genjet_pt(df170, "gen_taujet_pt_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df172 = quantities::tau::matching_genjet_pt(df171, "gen_taujet_pt_2__eleEsResoUp", 1, "dileptonpair__eleEsResoUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df173 = quantities::tau::matching_genjet_pt(df172, "gen_taujet_pt_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df174 = quantities::tau::matching_genjet_pt(df173, "gen_taujet_pt_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df175 = quantities::tau::matching_genjet_pt(df174, "gen_taujet_pt_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df176 = quantities::tau::matching_genjet_pt(df175, "gen_taujet_pt_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df177 = quantities::tau::matching_genjet_pt(df176, "gen_taujet_pt_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df178 = quantities::tau::matching_genjet_pt(df177, "gen_taujet_pt_2__eleEsResoDown", 1, "dileptonpair__eleEsResoDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df179 = quantities::tau::matching_genjet_pt(df178, "gen_taujet_pt_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df180 = quantities::tau::matching_genjet_pt(df179, "gen_taujet_pt_2__eleEsScaleDown", 1, "dileptonpair__eleEsScaleDown", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df181 = quantities::tau::matching_genjet_pt(df180, "gen_taujet_pt_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df182 = quantities::tau::matching_genjet_pt(df181, "gen_taujet_pt_2__eleEsScaleUp", 1, "dileptonpair__eleEsScaleUp", "Tau_jetIdx", "Jet_genJetIdx", "GenJet_pt");
    auto df183 = quantities::m_vis(df182, "gen_m_vis", {"gen_p4_1","gen_p4_2"});
    auto df184 = quantities::m_vis(df183, "gen_m_vis__tauEs3prong1pizeroDown", {"gen_p4_1__tauEs3prong1pizeroDown","gen_p4_2__tauEs3prong1pizeroDown"});
    auto df185 = quantities::m_vis(df184, "gen_m_vis__eleEsResoUp", {"gen_p4_1__eleEsResoUp","gen_p4_2__eleEsResoUp"});
    auto df186 = quantities::m_vis(df185, "gen_m_vis__tauEs3prong0pizeroDown", {"gen_p4_1__tauEs3prong0pizeroDown","gen_p4_2__tauEs3prong0pizeroDown"});
    auto df187 = quantities::m_vis(df186, "gen_m_vis__tauEs1prong0pizeroDown", {"gen_p4_1__tauEs1prong0pizeroDown","gen_p4_2__tauEs1prong0pizeroDown"});
    auto df188 = quantities::m_vis(df187, "gen_m_vis__tauEs3prong1pizeroUp", {"gen_p4_1__tauEs3prong1pizeroUp","gen_p4_2__tauEs3prong1pizeroUp"});
    auto df189 = quantities::m_vis(df188, "gen_m_vis__tauEs1prong1pizeroDown", {"gen_p4_1__tauEs1prong1pizeroDown","gen_p4_2__tauEs1prong1pizeroDown"});
    auto df190 = quantities::m_vis(df189, "gen_m_vis__tauEs1prong1pizeroUp", {"gen_p4_1__tauEs1prong1pizeroUp","gen_p4_2__tauEs1prong1pizeroUp"});
    auto df191 = quantities::m_vis(df190, "gen_m_vis__eleEsResoDown", {"gen_p4_1__eleEsResoDown","gen_p4_2__eleEsResoDown"});
    auto df192 = quantities::m_vis(df191, "gen_m_vis__tauEs1prong0pizeroUp", {"gen_p4_1__tauEs1prong0pizeroUp","gen_p4_2__tauEs1prong0pizeroUp"});
    auto df193 = quantities::m_vis(df192, "gen_m_vis__eleEsScaleDown", {"gen_p4_1__eleEsScaleDown","gen_p4_2__eleEsScaleDown"});
    auto df194 = quantities::m_vis(df193, "gen_m_vis__tauEs3prong0pizeroUp", {"gen_p4_1__tauEs3prong0pizeroUp","gen_p4_2__tauEs3prong0pizeroUp"});
    auto df195 = quantities::m_vis(df194, "gen_m_vis__eleEsScaleUp", {"gen_p4_1__eleEsScaleUp","gen_p4_2__eleEsScaleUp"});
    return df195;

}
