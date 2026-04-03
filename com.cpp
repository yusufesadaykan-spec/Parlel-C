int main() {
    const char* dosya = "parlel_data.bin";
    
    unsigned char veri[] = { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE };
    uint32_t boyut = sizeof(veri);

    printf("[C] Veri hazirlaniyor: %u byte\n", boyut);
    
    if (parlel_share_file(dosya, veri, boyut)) {
        printf("[C] Veri '%s' adresine basariyla yazildi.\n", dosya);
    } else {
        printf("[C] Hata: Dosya yazilamadi!\n");
    }

    return 0;
}