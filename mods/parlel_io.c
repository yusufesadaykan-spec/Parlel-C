#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * SHARE: Byte dizisini (buffer) boyut bilgisiyle birlikte dosyaya yazar.
 * [4 Byte Boyut] + [Veri...]
 */
int parlel_share(const char* filepath, unsigned char* content, uint32_t size) {
    // "wb" -> Write + Binary (Cross-platform için şart)
    FILE* f = fopen(filepath, "wb");
    if (!f) {
        perror("Parlel Share Hatasi");
        return 0;
    }

    // 1. Adım: Verinin boyutunu (uint32_t) dosyanın en başına yaz
    fwrite(&size, sizeof(uint32_t), 1, f);

    // 2. Adım: Gerçek byte içeriğini hemen arkasına yaz
    fwrite(content, 1, size, f);

    fclose(f);
    return 1;
}

unsigned char* parlel_load(const char* filepath, uint32_t* out_size) {
    FILE* f = fopen(filepath, "rb");
    if (!f) {
        perror("Parlel Load Hatasi");
        return NULL;
    }

    // 1. Adım: Dosyanın başındaki 4 byte'lık boyut bilgisini oku
    uint32_t size = 0;
    if (fread(&size, sizeof(uint32_t), 1, f) != 1) {
        fclose(f);
        return NULL;
    }

    // 2. Adım: Okunan boyut kadar RAM'de yer ayır
    unsigned char* buffer = (unsigned char*)malloc(size);
    if (!buffer) {
        fclose(f);
        return NULL;
    }

    // 3. Adım: Verinin geri kalanını ayırdığımız yere oku
    fread(buffer, 1, size, f);

    // Boyutu dışarıya (pointer ile) bildir
    *out_size = size;

    fclose(f);
    return buffer;
}

int parlel_share_file(const char* dosyaYolu, unsigned char* icerik, uint32_t boyut) {
    FILE* f = fopen(dosyaYolu, "wb"); // Binary yazma modu
    if (!f) {
        perror("Paylasim Hatasi");
        return 0;
    }

    // 1. Önce verinin kaç byte olduğunu (boyutunu) yazıyoruz
    fwrite(&boyut, sizeof(uint32_t), 1, f);

    // 2. Hemen ardından gerçek byte dizisini yazıyoruz
    fwrite(icerik, 1, boyut, f);

    fclose(f);
    return 1;
}

unsigned char* parlel_load_file(const char* dosyaYolu, uint32_t* okunanBoyut) {
    FILE* f = fopen(dosyaYolu, "rb"); // Binary okuma modu
    if (!f) {
        perror("Yukleme Hatasi");
        return NULL;
    }

    // 1. Dosyanın en başındaki 4 byte'lık boyutu oku
    uint32_t boyut = 0;
    if (fread(&boyut, sizeof(uint32_t), 1, f) != 1) {
        fclose(f);
        return NULL;
    }

    // 2. Okunan boyut kadar RAM'de yer ayır (malloc)
    unsigned char* tampon = (unsigned char*)malloc(boyut);
    if (!tampon) {
        fclose(f);
        return NULL;
    }

    // 3. Verinin geri kalanını (payload) tampona oku
    fread(tampon, 1, boyut, f);

    // Dışarıya boyut bilgisini gönder
    *okunanBoyut = boyut;

    fclose(f);
    return tampon;
}
