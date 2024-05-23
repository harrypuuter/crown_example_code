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
ROOT::RDF::RNode MuMuPairQuantities_mm (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = quantities::pt(df0, "pt_1", "p4_1");
    auto df2 = quantities::eta(df1, "eta_1", "p4_1");
    auto df3 = quantities::phi(df2, "phi_1", "p4_1");
    auto df4 = quantities::mass(df3, "mass_1", "p4_1");
    auto df5 = quantities::dxy(df4, "dxy_1", 0, "dileptonpair", "Muon_dxy");
    auto df6 = quantities::dz(df5, "dz_1", 0, "dileptonpair", "Muon_dz");
    auto df7 = quantities::charge(df6, "q_1", 0, "dileptonpair", "Muon_charge");
    auto df8 = quantities::isolation(df7, "iso_1", 0, "dileptonpair", "Muon_pfRelIso04_all");
    auto df9 = quantities::muon::is_global(df8, "is_global_1", 0, "dileptonpair", "Muon_isGlobal");
    auto df10 = quantities::pt(df9, "pt_2", "p4_2");
    auto df11 = quantities::eta(df10, "eta_2", "p4_2");
    auto df12 = quantities::phi(df11, "phi_2", "p4_2");
    auto df13 = quantities::mass(df12, "mass_2", "p4_2");
    auto df14 = quantities::dxy(df13, "dxy_2", 1, "dileptonpair", "Muon_dxy");
    auto df15 = quantities::dz(df14, "dz_2", 1, "dileptonpair", "Muon_dz");
    auto df16 = quantities::charge(df15, "q_2", 1, "dileptonpair", "Muon_charge");
    auto df17 = quantities::isolation(df16, "iso_2", 1, "dileptonpair", "Muon_pfRelIso04_all");
    auto df18 = quantities::muon::is_global(df17, "is_global_2", 1, "dileptonpair", "Muon_isGlobal");
    auto df19 = basefunctions::DefineQuantity(df18, "tau_decaymode_1", -1);
    auto df20 = basefunctions::DefineQuantity(df19, "tau_decaymode_2", -1);
    auto df21 = quantities::m_vis(df20, "m_vis", {"p4_1","p4_2"});
    auto df22 = quantities::pt_vis(df21, "pt_vis", {"p4_1","p4_2"});
    auto df23 = quantities::deltaR(df22, "deltaR_ditaupair", "p4_1", "p4_2");
    return df23;

}
