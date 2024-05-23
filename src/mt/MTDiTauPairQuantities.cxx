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
ROOT::RDF::RNode MTDiTauPairQuantities_mt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = quantities::pt(df0, "pt_1", "p4_1");
    auto df2 = quantities::eta(df1, "eta_1", "p4_1");
    auto df3 = quantities::phi(df2, "phi_1", "p4_1");
    auto df4 = quantities::mass(df3, "mass_1", "p4_1");
    auto df5 = quantities::dxy(df4, "dxy_1", 0, "dileptonpair", "Muon_dxy");
    auto df6 = quantities::dxy(df5, "dxy_1__tauEs3prong1pizeroDown", 0, "dileptonpair__tauEs3prong1pizeroDown", "Muon_dxy");
    auto df7 = quantities::dxy(df6, "dxy_1__tauEs1prong0pizeroDown", 0, "dileptonpair__tauEs1prong0pizeroDown", "Muon_dxy");
    auto df8 = quantities::dxy(df7, "dxy_1__tauEs3prong1pizeroUp", 0, "dileptonpair__tauEs3prong1pizeroUp", "Muon_dxy");
    auto df9 = quantities::dxy(df8, "dxy_1__tauEs1prong1pizeroDown", 0, "dileptonpair__tauEs1prong1pizeroDown", "Muon_dxy");
    auto df10 = quantities::dxy(df9, "dxy_1__tauEs1prong1pizeroUp", 0, "dileptonpair__tauEs1prong1pizeroUp", "Muon_dxy");
    auto df11 = quantities::dxy(df10, "dxy_1__tauEs1prong0pizeroUp", 0, "dileptonpair__tauEs1prong0pizeroUp", "Muon_dxy");
    auto df12 = quantities::dxy(df11, "dxy_1__tauEs3prong0pizeroDown", 0, "dileptonpair__tauEs3prong0pizeroDown", "Muon_dxy");
    auto df13 = quantities::dxy(df12, "dxy_1__tauEs3prong0pizeroUp", 0, "dileptonpair__tauEs3prong0pizeroUp", "Muon_dxy");
    auto df14 = quantities::dz(df13, "dz_1", 0, "dileptonpair", "Muon_dz");
    auto df15 = quantities::dz(df14, "dz_1__tauEs3prong1pizeroDown", 0, "dileptonpair__tauEs3prong1pizeroDown", "Muon_dz");
    auto df16 = quantities::dz(df15, "dz_1__tauEs1prong0pizeroDown", 0, "dileptonpair__tauEs1prong0pizeroDown", "Muon_dz");
    auto df17 = quantities::dz(df16, "dz_1__tauEs3prong1pizeroUp", 0, "dileptonpair__tauEs3prong1pizeroUp", "Muon_dz");
    auto df18 = quantities::dz(df17, "dz_1__tauEs1prong1pizeroDown", 0, "dileptonpair__tauEs1prong1pizeroDown", "Muon_dz");
    auto df19 = quantities::dz(df18, "dz_1__tauEs1prong1pizeroUp", 0, "dileptonpair__tauEs1prong1pizeroUp", "Muon_dz");
    auto df20 = quantities::dz(df19, "dz_1__tauEs1prong0pizeroUp", 0, "dileptonpair__tauEs1prong0pizeroUp", "Muon_dz");
    auto df21 = quantities::dz(df20, "dz_1__tauEs3prong0pizeroDown", 0, "dileptonpair__tauEs3prong0pizeroDown", "Muon_dz");
    auto df22 = quantities::dz(df21, "dz_1__tauEs3prong0pizeroUp", 0, "dileptonpair__tauEs3prong0pizeroUp", "Muon_dz");
    auto df23 = quantities::charge(df22, "q_1", 0, "dileptonpair", "Muon_charge");
    auto df24 = quantities::charge(df23, "q_1__tauEs3prong1pizeroDown", 0, "dileptonpair__tauEs3prong1pizeroDown", "Muon_charge");
    auto df25 = quantities::charge(df24, "q_1__tauEs1prong0pizeroDown", 0, "dileptonpair__tauEs1prong0pizeroDown", "Muon_charge");
    auto df26 = quantities::charge(df25, "q_1__tauEs3prong1pizeroUp", 0, "dileptonpair__tauEs3prong1pizeroUp", "Muon_charge");
    auto df27 = quantities::charge(df26, "q_1__tauEs1prong1pizeroDown", 0, "dileptonpair__tauEs1prong1pizeroDown", "Muon_charge");
    auto df28 = quantities::charge(df27, "q_1__tauEs1prong1pizeroUp", 0, "dileptonpair__tauEs1prong1pizeroUp", "Muon_charge");
    auto df29 = quantities::charge(df28, "q_1__tauEs1prong0pizeroUp", 0, "dileptonpair__tauEs1prong0pizeroUp", "Muon_charge");
    auto df30 = quantities::charge(df29, "q_1__tauEs3prong0pizeroDown", 0, "dileptonpair__tauEs3prong0pizeroDown", "Muon_charge");
    auto df31 = quantities::charge(df30, "q_1__tauEs3prong0pizeroUp", 0, "dileptonpair__tauEs3prong0pizeroUp", "Muon_charge");
    auto df32 = quantities::isolation(df31, "iso_1", 0, "dileptonpair", "Muon_pfRelIso04_all");
    auto df33 = quantities::isolation(df32, "iso_1__tauEs3prong1pizeroDown", 0, "dileptonpair__tauEs3prong1pizeroDown", "Muon_pfRelIso04_all");
    auto df34 = quantities::isolation(df33, "iso_1__tauEs1prong0pizeroDown", 0, "dileptonpair__tauEs1prong0pizeroDown", "Muon_pfRelIso04_all");
    auto df35 = quantities::isolation(df34, "iso_1__tauEs3prong1pizeroUp", 0, "dileptonpair__tauEs3prong1pizeroUp", "Muon_pfRelIso04_all");
    auto df36 = quantities::isolation(df35, "iso_1__tauEs1prong1pizeroDown", 0, "dileptonpair__tauEs1prong1pizeroDown", "Muon_pfRelIso04_all");
    auto df37 = quantities::isolation(df36, "iso_1__tauEs1prong1pizeroUp", 0, "dileptonpair__tauEs1prong1pizeroUp", "Muon_pfRelIso04_all");
    auto df38 = quantities::isolation(df37, "iso_1__tauEs1prong0pizeroUp", 0, "dileptonpair__tauEs1prong0pizeroUp", "Muon_pfRelIso04_all");
    auto df39 = quantities::isolation(df38, "iso_1__tauEs3prong0pizeroDown", 0, "dileptonpair__tauEs3prong0pizeroDown", "Muon_pfRelIso04_all");
    auto df40 = quantities::isolation(df39, "iso_1__tauEs3prong0pizeroUp", 0, "dileptonpair__tauEs3prong0pizeroUp", "Muon_pfRelIso04_all");
    auto df41 = quantities::muon::is_global(df40, "is_global_1", 0, "dileptonpair", "Muon_isGlobal");
    auto df42 = quantities::muon::is_global(df41, "is_global_1__tauEs3prong1pizeroDown", 0, "dileptonpair__tauEs3prong1pizeroDown", "Muon_isGlobal");
    auto df43 = quantities::muon::is_global(df42, "is_global_1__tauEs1prong0pizeroDown", 0, "dileptonpair__tauEs1prong0pizeroDown", "Muon_isGlobal");
    auto df44 = quantities::muon::is_global(df43, "is_global_1__tauEs3prong1pizeroUp", 0, "dileptonpair__tauEs3prong1pizeroUp", "Muon_isGlobal");
    auto df45 = quantities::muon::is_global(df44, "is_global_1__tauEs1prong1pizeroDown", 0, "dileptonpair__tauEs1prong1pizeroDown", "Muon_isGlobal");
    auto df46 = quantities::muon::is_global(df45, "is_global_1__tauEs1prong1pizeroUp", 0, "dileptonpair__tauEs1prong1pizeroUp", "Muon_isGlobal");
    auto df47 = quantities::muon::is_global(df46, "is_global_1__tauEs1prong0pizeroUp", 0, "dileptonpair__tauEs1prong0pizeroUp", "Muon_isGlobal");
    auto df48 = quantities::muon::is_global(df47, "is_global_1__tauEs3prong0pizeroDown", 0, "dileptonpair__tauEs3prong0pizeroDown", "Muon_isGlobal");
    auto df49 = quantities::muon::is_global(df48, "is_global_1__tauEs3prong0pizeroUp", 0, "dileptonpair__tauEs3prong0pizeroUp", "Muon_isGlobal");
    auto df50 = quantities::pt(df49, "pt_2", "p4_2");
    auto df51 = quantities::pt(df50, "pt_2__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown");
    auto df52 = quantities::pt(df51, "pt_2__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown");
    auto df53 = quantities::pt(df52, "pt_2__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp");
    auto df54 = quantities::pt(df53, "pt_2__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown");
    auto df55 = quantities::pt(df54, "pt_2__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp");
    auto df56 = quantities::pt(df55, "pt_2__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp");
    auto df57 = quantities::pt(df56, "pt_2__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown");
    auto df58 = quantities::pt(df57, "pt_2__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp");
    auto df59 = quantities::eta(df58, "eta_2", "p4_2");
    auto df60 = quantities::eta(df59, "eta_2__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown");
    auto df61 = quantities::eta(df60, "eta_2__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown");
    auto df62 = quantities::eta(df61, "eta_2__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp");
    auto df63 = quantities::eta(df62, "eta_2__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown");
    auto df64 = quantities::eta(df63, "eta_2__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp");
    auto df65 = quantities::eta(df64, "eta_2__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp");
    auto df66 = quantities::eta(df65, "eta_2__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown");
    auto df67 = quantities::eta(df66, "eta_2__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp");
    auto df68 = quantities::phi(df67, "phi_2", "p4_2");
    auto df69 = quantities::phi(df68, "phi_2__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown");
    auto df70 = quantities::phi(df69, "phi_2__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown");
    auto df71 = quantities::phi(df70, "phi_2__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp");
    auto df72 = quantities::phi(df71, "phi_2__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown");
    auto df73 = quantities::phi(df72, "phi_2__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp");
    auto df74 = quantities::phi(df73, "phi_2__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp");
    auto df75 = quantities::phi(df74, "phi_2__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown");
    auto df76 = quantities::phi(df75, "phi_2__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp");
    auto df77 = quantities::mass(df76, "mass_2", "p4_2");
    auto df78 = quantities::mass(df77, "mass_2__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown");
    auto df79 = quantities::mass(df78, "mass_2__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown");
    auto df80 = quantities::mass(df79, "mass_2__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp");
    auto df81 = quantities::mass(df80, "mass_2__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown");
    auto df82 = quantities::mass(df81, "mass_2__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp");
    auto df83 = quantities::mass(df82, "mass_2__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp");
    auto df84 = quantities::mass(df83, "mass_2__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown");
    auto df85 = quantities::mass(df84, "mass_2__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp");
    auto df86 = quantities::dxy(df85, "dxy_2", 1, "dileptonpair", "Tau_dxy");
    auto df87 = quantities::dxy(df86, "dxy_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_dxy");
    auto df88 = quantities::dxy(df87, "dxy_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_dxy");
    auto df89 = quantities::dxy(df88, "dxy_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_dxy");
    auto df90 = quantities::dxy(df89, "dxy_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_dxy");
    auto df91 = quantities::dxy(df90, "dxy_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_dxy");
    auto df92 = quantities::dxy(df91, "dxy_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_dxy");
    auto df93 = quantities::dxy(df92, "dxy_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_dxy");
    auto df94 = quantities::dxy(df93, "dxy_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_dxy");
    auto df95 = quantities::dz(df94, "dz_2", 1, "dileptonpair", "Tau_dz");
    auto df96 = quantities::dz(df95, "dz_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_dz");
    auto df97 = quantities::dz(df96, "dz_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_dz");
    auto df98 = quantities::dz(df97, "dz_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_dz");
    auto df99 = quantities::dz(df98, "dz_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_dz");
    auto df100 = quantities::dz(df99, "dz_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_dz");
    auto df101 = quantities::dz(df100, "dz_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_dz");
    auto df102 = quantities::dz(df101, "dz_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_dz");
    auto df103 = quantities::dz(df102, "dz_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_dz");
    auto df104 = quantities::charge(df103, "q_2", 1, "dileptonpair", "Tau_charge");
    auto df105 = quantities::charge(df104, "q_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_charge");
    auto df106 = quantities::charge(df105, "q_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_charge");
    auto df107 = quantities::charge(df106, "q_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_charge");
    auto df108 = quantities::charge(df107, "q_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_charge");
    auto df109 = quantities::charge(df108, "q_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_charge");
    auto df110 = quantities::charge(df109, "q_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_charge");
    auto df111 = quantities::charge(df110, "q_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_charge");
    auto df112 = quantities::charge(df111, "q_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_charge");
    auto df113 = quantities::isolation(df112, "iso_2", 1, "dileptonpair", "Tau_rawDeepTau2017v2p1VSjet");
    auto df114 = quantities::isolation(df113, "iso_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_rawDeepTau2017v2p1VSjet");
    auto df115 = quantities::isolation(df114, "iso_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_rawDeepTau2017v2p1VSjet");
    auto df116 = quantities::isolation(df115, "iso_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_rawDeepTau2017v2p1VSjet");
    auto df117 = quantities::isolation(df116, "iso_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_rawDeepTau2017v2p1VSjet");
    auto df118 = quantities::isolation(df117, "iso_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_rawDeepTau2017v2p1VSjet");
    auto df119 = quantities::isolation(df118, "iso_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_rawDeepTau2017v2p1VSjet");
    auto df120 = quantities::isolation(df119, "iso_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_rawDeepTau2017v2p1VSjet");
    auto df121 = quantities::isolation(df120, "iso_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_rawDeepTau2017v2p1VSjet");
    auto df122 = quantities::tau::decaymode(df121, "tau_decaymode_2", 1, "dileptonpair", "Tau_decayMode");
    auto df123 = quantities::tau::decaymode(df122, "tau_decaymode_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_decayMode");
    auto df124 = quantities::tau::decaymode(df123, "tau_decaymode_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_decayMode");
    auto df125 = quantities::tau::decaymode(df124, "tau_decaymode_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_decayMode");
    auto df126 = quantities::tau::decaymode(df125, "tau_decaymode_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_decayMode");
    auto df127 = quantities::tau::decaymode(df126, "tau_decaymode_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_decayMode");
    auto df128 = quantities::tau::decaymode(df127, "tau_decaymode_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_decayMode");
    auto df129 = quantities::tau::decaymode(df128, "tau_decaymode_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_decayMode");
    auto df130 = quantities::tau::decaymode(df129, "tau_decaymode_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_decayMode");
    auto df131 = quantities::tau::genmatch(df130, "tau_gen_match_2", 1, "dileptonpair", "Tau_genPartFlav");
    auto df132 = quantities::tau::genmatch(df131, "tau_gen_match_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_genPartFlav");
    auto df133 = quantities::tau::genmatch(df132, "tau_gen_match_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_genPartFlav");
    auto df134 = quantities::tau::genmatch(df133, "tau_gen_match_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_genPartFlav");
    auto df135 = quantities::tau::genmatch(df134, "tau_gen_match_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_genPartFlav");
    auto df136 = quantities::tau::genmatch(df135, "tau_gen_match_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_genPartFlav");
    auto df137 = quantities::tau::genmatch(df136, "tau_gen_match_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_genPartFlav");
    auto df138 = quantities::tau::genmatch(df137, "tau_gen_match_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_genPartFlav");
    auto df139 = quantities::tau::genmatch(df138, "tau_gen_match_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_genPartFlav");
    auto df140 = quantities::tau::matching_jet_pt(df139, "taujet_pt_2", 1, "dileptonpair", "Tau_jetIdx", "Jet_pt");
    auto df141 = quantities::tau::matching_jet_pt(df140, "taujet_pt_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_jetIdx", "Jet_pt");
    auto df142 = quantities::tau::matching_jet_pt(df141, "taujet_pt_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_jetIdx", "Jet_pt");
    auto df143 = quantities::tau::matching_jet_pt(df142, "taujet_pt_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_jetIdx", "Jet_pt");
    auto df144 = quantities::tau::matching_jet_pt(df143, "taujet_pt_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_jetIdx", "Jet_pt");
    auto df145 = quantities::tau::matching_jet_pt(df144, "taujet_pt_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_jetIdx", "Jet_pt");
    auto df146 = quantities::tau::matching_jet_pt(df145, "taujet_pt_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_jetIdx", "Jet_pt");
    auto df147 = quantities::tau::matching_jet_pt(df146, "taujet_pt_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_jetIdx", "Jet_pt");
    auto df148 = quantities::tau::matching_jet_pt(df147, "taujet_pt_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_jetIdx", "Jet_pt");
    auto df149 = quantities::tau::TauIDFlag(df148, "id_tau_vsJet_Loose_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df150 = quantities::tau::TauIDFlag(df149, "id_tau_vsJet_Medium_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df151 = quantities::tau::TauIDFlag(df150, "id_tau_vsJet_Tight_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df152 = quantities::tau::TauIDFlag(df151, "id_tau_vsJet_VTight_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df153 = quantities::tau::TauIDFlag(df152, "id_tau_vsJet_Loose_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df154 = quantities::tau::TauIDFlag(df153, "id_tau_vsJet_Medium_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df155 = quantities::tau::TauIDFlag(df154, "id_tau_vsJet_Tight_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df156 = quantities::tau::TauIDFlag(df155, "id_tau_vsJet_VTight_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df157 = quantities::tau::TauIDFlag(df156, "id_tau_vsJet_Loose_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df158 = quantities::tau::TauIDFlag(df157, "id_tau_vsJet_Medium_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df159 = quantities::tau::TauIDFlag(df158, "id_tau_vsJet_Tight_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df160 = quantities::tau::TauIDFlag(df159, "id_tau_vsJet_VTight_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df161 = quantities::tau::TauIDFlag(df160, "id_tau_vsJet_Loose_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df162 = quantities::tau::TauIDFlag(df161, "id_tau_vsJet_Medium_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df163 = quantities::tau::TauIDFlag(df162, "id_tau_vsJet_Tight_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df164 = quantities::tau::TauIDFlag(df163, "id_tau_vsJet_VTight_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df165 = quantities::tau::TauIDFlag(df164, "id_tau_vsJet_Loose_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df166 = quantities::tau::TauIDFlag(df165, "id_tau_vsJet_Medium_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df167 = quantities::tau::TauIDFlag(df166, "id_tau_vsJet_Tight_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df168 = quantities::tau::TauIDFlag(df167, "id_tau_vsJet_VTight_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df169 = quantities::tau::TauIDFlag(df168, "id_tau_vsJet_Loose_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df170 = quantities::tau::TauIDFlag(df169, "id_tau_vsJet_Medium_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df171 = quantities::tau::TauIDFlag(df170, "id_tau_vsJet_Tight_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df172 = quantities::tau::TauIDFlag(df171, "id_tau_vsJet_VTight_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df173 = quantities::tau::TauIDFlag(df172, "id_tau_vsJet_Loose_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df174 = quantities::tau::TauIDFlag(df173, "id_tau_vsJet_Medium_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df175 = quantities::tau::TauIDFlag(df174, "id_tau_vsJet_Tight_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df176 = quantities::tau::TauIDFlag(df175, "id_tau_vsJet_VTight_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df177 = quantities::tau::TauIDFlag(df176, "id_tau_vsJet_Loose_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df178 = quantities::tau::TauIDFlag(df177, "id_tau_vsJet_Medium_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df179 = quantities::tau::TauIDFlag(df178, "id_tau_vsJet_Tight_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df180 = quantities::tau::TauIDFlag(df179, "id_tau_vsJet_VTight_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df181 = quantities::tau::TauIDFlag(df180, "id_tau_vsJet_Loose_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 4);
    auto df182 = quantities::tau::TauIDFlag(df181, "id_tau_vsJet_Medium_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 5);
    auto df183 = quantities::tau::TauIDFlag(df182, "id_tau_vsJet_Tight_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 6);
    auto df184 = quantities::tau::TauIDFlag(df183, "id_tau_vsJet_VTight_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSjet", 7);
    auto df185 = quantities::tau::TauIDFlag(df184, "id_tau_vsEle_VVLoose_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df186 = quantities::tau::TauIDFlag(df185, "id_tau_vsEle_VLoose_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df187 = quantities::tau::TauIDFlag(df186, "id_tau_vsEle_Loose_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df188 = quantities::tau::TauIDFlag(df187, "id_tau_vsEle_Medium_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df189 = quantities::tau::TauIDFlag(df188, "id_tau_vsEle_Tight_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df190 = quantities::tau::TauIDFlag(df189, "id_tau_vsEle_VTight_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df191 = quantities::tau::TauIDFlag(df190, "id_tau_vsEle_VVTight_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df192 = quantities::tau::TauIDFlag(df191, "id_tau_vsEle_VVLoose_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df193 = quantities::tau::TauIDFlag(df192, "id_tau_vsEle_VLoose_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df194 = quantities::tau::TauIDFlag(df193, "id_tau_vsEle_Loose_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df195 = quantities::tau::TauIDFlag(df194, "id_tau_vsEle_Medium_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df196 = quantities::tau::TauIDFlag(df195, "id_tau_vsEle_Tight_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df197 = quantities::tau::TauIDFlag(df196, "id_tau_vsEle_VTight_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df198 = quantities::tau::TauIDFlag(df197, "id_tau_vsEle_VVTight_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df199 = quantities::tau::TauIDFlag(df198, "id_tau_vsEle_VVLoose_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df200 = quantities::tau::TauIDFlag(df199, "id_tau_vsEle_VLoose_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df201 = quantities::tau::TauIDFlag(df200, "id_tau_vsEle_Loose_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df202 = quantities::tau::TauIDFlag(df201, "id_tau_vsEle_Medium_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df203 = quantities::tau::TauIDFlag(df202, "id_tau_vsEle_Tight_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df204 = quantities::tau::TauIDFlag(df203, "id_tau_vsEle_VTight_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df205 = quantities::tau::TauIDFlag(df204, "id_tau_vsEle_VVTight_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df206 = quantities::tau::TauIDFlag(df205, "id_tau_vsEle_VVLoose_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df207 = quantities::tau::TauIDFlag(df206, "id_tau_vsEle_VLoose_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df208 = quantities::tau::TauIDFlag(df207, "id_tau_vsEle_Loose_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df209 = quantities::tau::TauIDFlag(df208, "id_tau_vsEle_Medium_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df210 = quantities::tau::TauIDFlag(df209, "id_tau_vsEle_Tight_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df211 = quantities::tau::TauIDFlag(df210, "id_tau_vsEle_VTight_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df212 = quantities::tau::TauIDFlag(df211, "id_tau_vsEle_VVTight_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df213 = quantities::tau::TauIDFlag(df212, "id_tau_vsEle_VVLoose_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df214 = quantities::tau::TauIDFlag(df213, "id_tau_vsEle_VLoose_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df215 = quantities::tau::TauIDFlag(df214, "id_tau_vsEle_Loose_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df216 = quantities::tau::TauIDFlag(df215, "id_tau_vsEle_Medium_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df217 = quantities::tau::TauIDFlag(df216, "id_tau_vsEle_Tight_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df218 = quantities::tau::TauIDFlag(df217, "id_tau_vsEle_VTight_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df219 = quantities::tau::TauIDFlag(df218, "id_tau_vsEle_VVTight_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df220 = quantities::tau::TauIDFlag(df219, "id_tau_vsEle_VVLoose_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df221 = quantities::tau::TauIDFlag(df220, "id_tau_vsEle_VLoose_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df222 = quantities::tau::TauIDFlag(df221, "id_tau_vsEle_Loose_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df223 = quantities::tau::TauIDFlag(df222, "id_tau_vsEle_Medium_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df224 = quantities::tau::TauIDFlag(df223, "id_tau_vsEle_Tight_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df225 = quantities::tau::TauIDFlag(df224, "id_tau_vsEle_VTight_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df226 = quantities::tau::TauIDFlag(df225, "id_tau_vsEle_VVTight_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df227 = quantities::tau::TauIDFlag(df226, "id_tau_vsEle_VVLoose_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df228 = quantities::tau::TauIDFlag(df227, "id_tau_vsEle_VLoose_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df229 = quantities::tau::TauIDFlag(df228, "id_tau_vsEle_Loose_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df230 = quantities::tau::TauIDFlag(df229, "id_tau_vsEle_Medium_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df231 = quantities::tau::TauIDFlag(df230, "id_tau_vsEle_Tight_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df232 = quantities::tau::TauIDFlag(df231, "id_tau_vsEle_VTight_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df233 = quantities::tau::TauIDFlag(df232, "id_tau_vsEle_VVTight_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df234 = quantities::tau::TauIDFlag(df233, "id_tau_vsEle_VVLoose_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df235 = quantities::tau::TauIDFlag(df234, "id_tau_vsEle_VLoose_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df236 = quantities::tau::TauIDFlag(df235, "id_tau_vsEle_Loose_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df237 = quantities::tau::TauIDFlag(df236, "id_tau_vsEle_Medium_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df238 = quantities::tau::TauIDFlag(df237, "id_tau_vsEle_Tight_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df239 = quantities::tau::TauIDFlag(df238, "id_tau_vsEle_VTight_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df240 = quantities::tau::TauIDFlag(df239, "id_tau_vsEle_VVTight_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df241 = quantities::tau::TauIDFlag(df240, "id_tau_vsEle_VVLoose_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 2);
    auto df242 = quantities::tau::TauIDFlag(df241, "id_tau_vsEle_VLoose_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 3);
    auto df243 = quantities::tau::TauIDFlag(df242, "id_tau_vsEle_Loose_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 4);
    auto df244 = quantities::tau::TauIDFlag(df243, "id_tau_vsEle_Medium_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 5);
    auto df245 = quantities::tau::TauIDFlag(df244, "id_tau_vsEle_Tight_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 6);
    auto df246 = quantities::tau::TauIDFlag(df245, "id_tau_vsEle_VTight_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 7);
    auto df247 = quantities::tau::TauIDFlag(df246, "id_tau_vsEle_VVTight_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSe", 8);
    auto df248 = quantities::tau::TauIDFlag(df247, "id_tau_vsMu_VLoose_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df249 = quantities::tau::TauIDFlag(df248, "id_tau_vsMu_Loose_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df250 = quantities::tau::TauIDFlag(df249, "id_tau_vsMu_Medium_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df251 = quantities::tau::TauIDFlag(df250, "id_tau_vsMu_Tight_2", 1, "dileptonpair", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df252 = quantities::tau::TauIDFlag(df251, "id_tau_vsMu_VLoose_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df253 = quantities::tau::TauIDFlag(df252, "id_tau_vsMu_Loose_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df254 = quantities::tau::TauIDFlag(df253, "id_tau_vsMu_Medium_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df255 = quantities::tau::TauIDFlag(df254, "id_tau_vsMu_Tight_2__tauEs3prong1pizeroDown", 1, "dileptonpair__tauEs3prong1pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df256 = quantities::tau::TauIDFlag(df255, "id_tau_vsMu_VLoose_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df257 = quantities::tau::TauIDFlag(df256, "id_tau_vsMu_Loose_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df258 = quantities::tau::TauIDFlag(df257, "id_tau_vsMu_Medium_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df259 = quantities::tau::TauIDFlag(df258, "id_tau_vsMu_Tight_2__tauEs1prong0pizeroDown", 1, "dileptonpair__tauEs1prong0pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df260 = quantities::tau::TauIDFlag(df259, "id_tau_vsMu_VLoose_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df261 = quantities::tau::TauIDFlag(df260, "id_tau_vsMu_Loose_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df262 = quantities::tau::TauIDFlag(df261, "id_tau_vsMu_Medium_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df263 = quantities::tau::TauIDFlag(df262, "id_tau_vsMu_Tight_2__tauEs3prong1pizeroUp", 1, "dileptonpair__tauEs3prong1pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df264 = quantities::tau::TauIDFlag(df263, "id_tau_vsMu_VLoose_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df265 = quantities::tau::TauIDFlag(df264, "id_tau_vsMu_Loose_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df266 = quantities::tau::TauIDFlag(df265, "id_tau_vsMu_Medium_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df267 = quantities::tau::TauIDFlag(df266, "id_tau_vsMu_Tight_2__tauEs1prong1pizeroDown", 1, "dileptonpair__tauEs1prong1pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df268 = quantities::tau::TauIDFlag(df267, "id_tau_vsMu_VLoose_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df269 = quantities::tau::TauIDFlag(df268, "id_tau_vsMu_Loose_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df270 = quantities::tau::TauIDFlag(df269, "id_tau_vsMu_Medium_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df271 = quantities::tau::TauIDFlag(df270, "id_tau_vsMu_Tight_2__tauEs1prong1pizeroUp", 1, "dileptonpair__tauEs1prong1pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df272 = quantities::tau::TauIDFlag(df271, "id_tau_vsMu_VLoose_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df273 = quantities::tau::TauIDFlag(df272, "id_tau_vsMu_Loose_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df274 = quantities::tau::TauIDFlag(df273, "id_tau_vsMu_Medium_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df275 = quantities::tau::TauIDFlag(df274, "id_tau_vsMu_Tight_2__tauEs1prong0pizeroUp", 1, "dileptonpair__tauEs1prong0pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df276 = quantities::tau::TauIDFlag(df275, "id_tau_vsMu_VLoose_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df277 = quantities::tau::TauIDFlag(df276, "id_tau_vsMu_Loose_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df278 = quantities::tau::TauIDFlag(df277, "id_tau_vsMu_Medium_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df279 = quantities::tau::TauIDFlag(df278, "id_tau_vsMu_Tight_2__tauEs3prong0pizeroDown", 1, "dileptonpair__tauEs3prong0pizeroDown", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df280 = quantities::tau::TauIDFlag(df279, "id_tau_vsMu_VLoose_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 1);
    auto df281 = quantities::tau::TauIDFlag(df280, "id_tau_vsMu_Loose_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 2);
    auto df282 = quantities::tau::TauIDFlag(df281, "id_tau_vsMu_Medium_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 3);
    auto df283 = quantities::tau::TauIDFlag(df282, "id_tau_vsMu_Tight_2__tauEs3prong0pizeroUp", 1, "dileptonpair__tauEs3prong0pizeroUp", "Tau_idDeepTau2017v2p1VSmu", 4);
    auto df284 = basefunctions::DefineQuantity(df283, "tau_decaymode_1", -1);
    auto df285 = quantities::m_vis(df284, "m_vis", {"p4_1","p4_2"});
    auto df286 = quantities::m_vis(df285, "m_vis__tauEs3prong1pizeroDown", {"p4_1","p4_2__tauEs3prong1pizeroDown"});
    auto df287 = quantities::m_vis(df286, "m_vis__tauEs1prong0pizeroDown", {"p4_1","p4_2__tauEs1prong0pizeroDown"});
    auto df288 = quantities::m_vis(df287, "m_vis__tauEs3prong1pizeroUp", {"p4_1","p4_2__tauEs3prong1pizeroUp"});
    auto df289 = quantities::m_vis(df288, "m_vis__tauEs1prong1pizeroDown", {"p4_1","p4_2__tauEs1prong1pizeroDown"});
    auto df290 = quantities::m_vis(df289, "m_vis__tauEs1prong1pizeroUp", {"p4_1","p4_2__tauEs1prong1pizeroUp"});
    auto df291 = quantities::m_vis(df290, "m_vis__tauEs1prong0pizeroUp", {"p4_1","p4_2__tauEs1prong0pizeroUp"});
    auto df292 = quantities::m_vis(df291, "m_vis__tauEs3prong0pizeroDown", {"p4_1","p4_2__tauEs3prong0pizeroDown"});
    auto df293 = quantities::m_vis(df292, "m_vis__tauEs3prong0pizeroUp", {"p4_1","p4_2__tauEs3prong0pizeroUp"});
    auto df294 = quantities::pt_vis(df293, "pt_vis", {"p4_1","p4_2"});
    auto df295 = quantities::pt_vis(df294, "pt_vis__tauEs3prong1pizeroDown", {"p4_1","p4_2__tauEs3prong1pizeroDown"});
    auto df296 = quantities::pt_vis(df295, "pt_vis__tauEs1prong0pizeroDown", {"p4_1","p4_2__tauEs1prong0pizeroDown"});
    auto df297 = quantities::pt_vis(df296, "pt_vis__tauEs3prong1pizeroUp", {"p4_1","p4_2__tauEs3prong1pizeroUp"});
    auto df298 = quantities::pt_vis(df297, "pt_vis__tauEs1prong1pizeroDown", {"p4_1","p4_2__tauEs1prong1pizeroDown"});
    auto df299 = quantities::pt_vis(df298, "pt_vis__tauEs1prong1pizeroUp", {"p4_1","p4_2__tauEs1prong1pizeroUp"});
    auto df300 = quantities::pt_vis(df299, "pt_vis__tauEs1prong0pizeroUp", {"p4_1","p4_2__tauEs1prong0pizeroUp"});
    auto df301 = quantities::pt_vis(df300, "pt_vis__tauEs3prong0pizeroDown", {"p4_1","p4_2__tauEs3prong0pizeroDown"});
    auto df302 = quantities::pt_vis(df301, "pt_vis__tauEs3prong0pizeroUp", {"p4_1","p4_2__tauEs3prong0pizeroUp"});
    auto df303 = quantities::deltaR(df302, "deltaR_ditaupair", "p4_1", "p4_2");
    auto df304 = quantities::deltaR(df303, "deltaR_ditaupair__tauEs3prong1pizeroDown", "p4_1", "p4_2__tauEs3prong1pizeroDown");
    auto df305 = quantities::deltaR(df304, "deltaR_ditaupair__tauEs1prong0pizeroDown", "p4_1", "p4_2__tauEs1prong0pizeroDown");
    auto df306 = quantities::deltaR(df305, "deltaR_ditaupair__tauEs3prong1pizeroUp", "p4_1", "p4_2__tauEs3prong1pizeroUp");
    auto df307 = quantities::deltaR(df306, "deltaR_ditaupair__tauEs1prong1pizeroDown", "p4_1", "p4_2__tauEs1prong1pizeroDown");
    auto df308 = quantities::deltaR(df307, "deltaR_ditaupair__tauEs1prong1pizeroUp", "p4_1", "p4_2__tauEs1prong1pizeroUp");
    auto df309 = quantities::deltaR(df308, "deltaR_ditaupair__tauEs1prong0pizeroUp", "p4_1", "p4_2__tauEs1prong0pizeroUp");
    auto df310 = quantities::deltaR(df309, "deltaR_ditaupair__tauEs3prong0pizeroDown", "p4_1", "p4_2__tauEs3prong0pizeroDown");
    auto df311 = quantities::deltaR(df310, "deltaR_ditaupair__tauEs3prong0pizeroUp", "p4_1", "p4_2__tauEs3prong0pizeroUp");
    return df311;

}
