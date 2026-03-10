@echo off
title Data Analyst - Refresh Mirror Database
color 0E

echo ======================================================
echo       SISTEM REFRESH MIRRORDATABASE ANALYST
echo ======================================================
echo.
echo Sedang mencari file backup terbaru dan 
echo memperbarui database db_mirror_analyst...
echo.

:: 1. Masuk ke folder kerja (Folder tempat mirror_db.py berada)
cd /d " ............backups"

:: 2. Jalankan Python untuk Mirroring
"lokasiinstal python \python.exe" dummy_db.py 
:: Ganti dengan path ke python.exe di sistem Anda

:: 3. Cek Status Keberhasilan
if %ERRORLEVEL% EQU 0 (
    color 0A
    echo.
    echo ======================================================
    echo ✅ BERHASIL! Database Mirror sudah diperbarui.
    echo Data Analyst sekarang bisa bekerja dengan data terbaru.
    echo ======================================================
) else (
    color 0C
    echo.
    echo ======================================================
    echo ❌ GAGAL! Terjadi kesalahan saat update mirror.
    echo Pastikan tidak ada program lain yang mengunci database.
    echo ======================================================
)

echo.
echo Tekan tombol apa saja untuk menutup jendela ini...
pause > nul
exit