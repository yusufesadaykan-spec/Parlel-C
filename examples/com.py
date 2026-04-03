dosya_yolu = "parlel_data.bin"

print("[Python] C'den gelen veri bekleniyor...")
gelen_veri = parlel_load_file(dosya_yolu)

if gelen_veri:
    print(f"[Python] Veri alindi! Boyut: {len(gelen_veri)} byte")
    # Veriyi HEX formatında gösterelim
    print(f"[Python] Icerik (HEX): {gelen_veri.hex().upper()}")
    
    # İstersek her bir byte'a offset ile erişebiliriz
    for i, b in enumerate(gelen_veri):
        print(f"  Offset {i}: {hex(b)}")
else:
    print("[Python] Veri yuklenemedi.")