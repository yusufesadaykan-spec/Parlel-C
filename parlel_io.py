import struct
import os

def parlel_share_file(filepath, content: bytes):
    with open(filepath, "wb") as f:
        f.write(struct.pack('<I', len(content)))
        f.write(content)

def parlel_load_file(filepath):
    if not os.path.exists(filepath): return None
    with open(filepath, "rb") as f:
        size = struct.unpack('<I', f.read(4))[0]
        return f.read(size)

def parlel_share(source_bytes: bytes):
    """Veriyi paketlenmiş (Header + Data) bir byte dizisi olarak döndürür."""
    return struct.pack('<I', len(source_bytes)) + source_bytes

def parlel_load(packed_bytes: bytes):
    """Paketlenmiş byte dizisinden veriyi ayrıştırır."""
    size = struct.unpack('<I', packed_bytes[:4])[0]
    return packed_bytes[4:4+size]