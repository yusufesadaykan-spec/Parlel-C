#include <iostream>
#include "src/moduler.cpp"

std::vector<std::string> getFilePaths(int argc, char* argv[]) {
    std::vector<std::string> paths;

    // i = 0 her zaman programın kendi adıdır (exe yolu).
    // Bu yüzden gerçek dosyalar i = 1'den başlar.
    for (int i = 1; i < argc; ++i) {
        paths.push_back(argv[i]);
    }

    return paths;
}

int main(int argc, char* args[])
{
    // En az 3 argüman lazım (finalBoss, en az 1 modül ve çıktı dosyası)
    if (argc < 4) {
        std::cout << "Hata: Eksik arguman! \nKullanim: ./Parlel <ana_kod> <modul1> <cikti_dosyasi>" << std::endl;
        return 1;
    }

    // 1. İlk argümanı (test.cprl) sakla
    std::string finalBoss = args[1];

    // 2. Çıktı dosyasını (hello.cpp) belirle
    std::string outputFileName = args[argc - 1]; 

    moduler Parlel;

    // 3. Aradaki tüm dosyaları (default.cpp vb.) modül olarak topla
    // i=2'den başla, son elemana (output) kadar git
    for (int i = 2; i < argc-1; ++i) {
        Parlel.archs.push_back(args[i]);
        std::cout << args[i] << "\n";
    }

    std::cout << "Mixer is doing some think" << std::endl;
    Parlel.getModules(outputFileName);

    std::cout << "Were making progress" << std::endl;
    Parlel.loadParse(parser::parse(readFile(finalBoss)), outputFileName);

    std::cout << "Mama Done!! " << outputFileName << std::endl;

    return 0;
}