#include <iostream>
using namespace std;

class MasukUniversitas {
	private:
	int uangPendaftaran;
	// isi daftar variable yang dibutuhkan di bawah ini
	int uangSemesterPertama;
	int uangBangunan;
	int totalBiaya;
public:
	MasukUniversitas() {
		uangPendaftaran = 0;
		// isi nilai default variable yang dibutuhkan di bawah ini
		uangSemesterPertama = 0;
		uangBangunan = 0;
		totalBiaya = 0;
	}
	virtual void namaJalurMasuk() { return; }
	// isi disini dengan fungsi virtual yang dibutuhkan
	virtual void hitungTotalBiaya() { return; }
	virtual void tampilkanTotalBiaya() { return; }
	virtual void input() { return; }

	void setUangPendaftaran(int nilai) {
		this->uangPendaftaran = nilai;
	}
	float getUangPendaftaran() {
		return uangPendaftaran;
	}
	// isi setter dan getter variable yang dibutuhkan di bawah ini 
	void setUangSemesterPertama(int nilai) {
		this->uangSemesterPertama = nilai;
	}
	float getUangSemesterPertama() {
		return uangSemesterPertama;
	}
	void setUangBangunan(int nilai) {
		this->uangBangunan = nilai;
	}
	float getUangBangunan() {
		return uangBangunan;
	}
};
class SNBT : public MasukUniversitas {
	// isi disini untuk melengkapi class SNBT
public:
	void input() {
		float uangPendaftaran;
		float uangSemester;
		float uangBangunan;
		cout << "\nMasukkan uang pendaftaran: ";
		cin >> uangPendaftaran;
		cout << "\nMasukkan uang semester: ";
		cin >> uangSemester;
		cout << "\nMasukkan uang bangunan: ";
		cin >> uangBangunan;
		setUangPendaftaran(uangPendaftaran);
		setUangSemesterPertama(uangSemester);
		setUangBangunan(uangBangunan);
	}
	void hitungTotalBiaya() {
		float totalBiaya = getUangPendaftaran() + getUangSemesterPertama() + getUangBangunan();
		cout << "Total Biaya: " << totalBiaya << endl;
	}
	void tampilkanTotalBiaya() {
		cout << "\nKategori: Mahal\n";
		cout << "Rekomendasi : Tidak Direkomendasikan\n\n";
	}
};
class SNBP : public MasukUniversitas {
	// isi disini untuk melengkapi class SNBP
public:
	void input() {
		getUangPendaftaran();
		getUangSemesterPertama();
	}
	float hitungTotalBiaya(float uangPendaftaran,
		float uangSemesterPertama) {
		float totalBiaya = uangPendaftaran + uangSemesterPertama;
		cout << "Total Biaya: " << totalBiaya << endl;
		return totalBiaya;
	}
	void tampilkanTotalBiaya() {
		cout << "\nKategori: Sedang\n";
		cout << "Rekomendasi : Dipertimbangkan\n\n";
	}
};
int main() {
	// isi disini untuk fungsi main
	MasukUniversitas* masuk;
	int pilih;
	SNBT snbt;
	SNBP snbp;
	do {
		cout << "Pilih Jalur Masuk:\n";
		cout << "1. SNBT\n";
		cout << "2. SNBP\n";
		cout << "3. Keluar\n";
		cout << "Pilih: ";
		cin >> pilih;
		switch (pilih) {
		case 1:
			masuk = &snbt;
			masuk->input();
			snbt.hitungTotalBiaya();
			snbt.tampilkanTotalBiaya();
			system("pause");
			system("cls");
			break;
		case 2:
			float uangPendaftaran1;
			float uangSemester1;
			cout << "\nMasukkan uang pendaftaran: ";
			cin >> uangPendaftaran1;
			cout << "\nMasukkan uang semester: ";
			cin >> uangSemester1;
			snbp.hitungTotalBiaya(uangPendaftaran1, uangSemester1);
			snbp.tampilkanTotalBiaya();
			system("pause");
			system("cls");
			break;
		case 3:
			break;
		}
	} while (pilih != 3);
	return 0;
}