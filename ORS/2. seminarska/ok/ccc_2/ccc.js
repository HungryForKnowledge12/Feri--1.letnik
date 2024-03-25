// Definicije spremenljivk za delo z DOM
const znaki = document.querySelectorAll(".znaki");
const prikazVnosa = document.querySelector(".vnos");
const prikazIzpisa = document.querySelector(".izpis");

let vnos = "";

// Dodajanje številk k vnosu
function dodajanjeStevil(st) {
  vnos += st;
  prikazVnosa.innerHTML = vnos;
}

// Dodajanje operacij ali drugih znakov k vnosu
function dodajanjeCrk(crka) {
  vnos += crka;
  prikazVnosa.innerHTML = vnos;
}

// Dodajanje operacije seštevanja
function sestevanje() {
  vnos += "+";
  prikazVnosa.innerHTML = vnos;
}

// Dodajanje operacije odštevanja
function odstevanje() {
  vnos += "-";
  prikazVnosa.innerHTML = vnos;
}

// Dodajanje operacije množenja
function mnozenje() {
  vnos += "*";
  prikazVnosa.innerHTML = vnos;
}

// Dodajanje operacije deljenja
function deljenje() {
  vnos += "/";
  prikazVnosa.innerHTML = vnos;
}

// Izračun vnesenih podatkov
function racunanje() {
  let rezultat;

  // Izvedba izračuna z uporabo eval
  let izracun = new Function('return ' + vnos);
  rezultat = izracun();

  prikazIzpisa.innerHTML = rezultat;
}

// Funkcija za čiščenje vsega vnosa in izpisa
function pocisti() {
  vnos = "";
  prikazVnosa.innerHTML = "";
  prikazIzpisa.innerHTML = "";
}

// Funkcija za brisanje zadnjega znaka v vnosi
function brisi() {
  vnos = vnos.substring(0, vnos.length - 1);
  prikazVnosa.innerHTML = vnos;
}

// Funkcija za dodajanje oklepajev v izraz
function oklepaji() {
  if (!vnos.includes("(") || vnos.lastIndexOf("(") < vnos.lastIndexOf(")")) {
      vnos += "(";
  } else if (
      vnos.includes("(") &&
      (!vnos.includes(")") || (vnos.lastIndexOf("(") > vnos.lastIndexOf(")"))))
      {
        vnos += ")";
  } else {
      vnos += vrednost;
  }
  prikazVnosa.innerHTML = vnos;
}

// Ta funkcija doda decimalno vejico v vnos, če ta še ni prisotna v trenutnem številu.
function decimalnaVejica() {
  var zadnjeSt = vnos.split(/[\+\-\*\/]/).pop();
    if (!zadnjeSt.includes(".")) {
        vnos += ".";
    }
}

// Ta funkcija doda znak za ostanek (%) v vnos.
function ostanek() {
  vnos += "%";
  prikazVnosa.innerHTML = vnos;
}

// Ta funkcija izvede potenciranje.
function potenciranje() {
  vnos += "**";
  prikazVnosa.innerHTML = vnos;
}

// Ta funkcija izračuna koren trenutnega vnosa.
function koren() {
  var kvKoren = Math.sqrt(vnos);
  prikazIzpisa.innerHTML = kvKoren;
}

// Ta funkcija izračuna koren trenutnega vnosa.
function decVbin() {
  let dec = vnos;
  let bin = "";
  let rev = "";

  while (dec > 0) {
    bin += dec % 2;
    dec = dec / 2 | 0;
  }

  for (let i = bin.length - 1; i >= 0; i--) {
    rev += bin[i];
  }

  prikazIzpisa.innerHTML = rev;
}

// Pretvori decimalno število v osmiški sistem
function decVoct() {
  let dec = vnos;
  let oct = "";
  let rev = "";

  while (dec > 0) {
    oct += dec % 8;
    dec = dec / 8 | 0;
  }

  for (let i = oct.length - 1; i >= 0; i--) {
    rev += oct[i];
  }

  prikazIzpisa.innerHTML = rev;
}

// Pretvori decimalno število v šestnajstiški sistem
function decVhex() {
  let dec = vnos;
  let hex = [];
  let i = 0;
  let rev = "";
  let hexVr = {10: "A", 11: "B", 12: "C", 13: "D", 14: "E", 15: "F"};

  while (dec > 0) {
    hex[i] = dec % 16;
    dec = dec / 16 | 0;
    i++;
  }

  for (let i = 0; i < hex.length; i++) {
    if (hex[i] >= 10) {
        hex[i] = hexVr[hex[i]];
    }
  }

  for (let i = hex.length - 1; i >= 0; i--) {
    rev += [hex[i]];
  }

  prikazIzpisa.innerHTML = rev;
}


// Pretvori binarno število v decimalni sistem.
function binVdec() {
  let bin = vnos;
  let dec = 0;
  let i = 0;

  while (bin > 0) {
      let zadnjaSt = bin % 10;
      bin = bin - zadnjaSt;
      bin /= 10;

      dec += zadnjaSt * (2 ** i);
      i++;
  }

    prikazIzpisa.innerHTML = dec;
}

// Pretvori osmiško število v decimalni sistem.
function octVdec() {
  let oct = vnos;
  let dec = 0;
  let i = 0;

  while (oct > 0) {
      let zadnjaSt = oct % 10;
      oct = oct - zadnjaSt;
      oct /= 10;

      dec += zadnjaSt * (8 ** i);
      i++;
  }

  prikazIzpisa.innerHTML = dec;
}

// Pretvori šestnajstiško število v decimalni sistem.
function hexVdec() {
    let hex = vnos;
  const vr = {"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9, "A": 10, "B": 11, "C": 12, "D": 13, "E": 14, "F": 15 };
  let dec = 0;

  for (let i = 0; i < hex.length; i++) {
    const posHex = hex[i];
    const vrPosHex = vr[posHex];

    dec *= 16;
    dec += vrPosHex;
  }
  prikazIzpisa.innerHTML = dec;
}

// Ta funkcija preveri, ali je logična operacija že prisotna v vnosu.
function vnosLogicneVrate(operacija) {
  if (!vnos.includes('AND') && !vnos.includes('OR') && !vnos.includes('XOR') && !vnos.includes('NOT') && !vnos.includes('NAND') && !vnos.includes('NOR')) {
    vnos += ` ${operacija} `;
  } else {
    prikazIzpisa.innerHTML = "Nekje si se zmotil";
  }
  prikazVnosa.innerHTML = vnos;
}

// Ta funkcija izvede logično operacijo AND.
function bAND() {
  let operator = vnos.split(' AND ');
  if (operator.length === 2 && operator.every(op => /^[01]+$/.test(op))) {
    let result = (parseInt(operator[0], 2) & parseInt(operator[1], 2)).toString(2);
    prikazIzpisa.innerHTML = result;
  } else {
    prikazIzpisa.innerHTML = "Napačen vnos";
  }
}

// Ta funkcija izvede logično operacijo OR.
function bOR() {
  let operator = vnos.split(' OR ');
  if (operator.length === 2 && operator.every(op => /^[01]+$/.test(op))) {
    let result = (parseInt(operator[0], 2) | parseInt(operator[1], 2)).toString(2);
    prikazIzpisa.innerHTML = result;
  } else {
    prikazIzpisa.innerHTML = "Napačen vnos";
  }
}

// Ta funkcija izvede logično operacijo NOT.
function bNOT() {
  if (/^[01]+$/.test(vnos)) {
    let result = vnos.split('').map(bit => bit === '0' ? '1' : '0').join('');
    vnos = result;
    prikazVnosa.innerHTML = vnos;
  } else {
    prikazIzpisa.innerHTML = "Napačen vnos";
  }
}

// Ta funkcija izvede logično operacijo XOR.
function bXOR() {
  let operator = vnos.trim().split(' XOR ');
  if (operator.length === 2 && operator.every(op => /^[01]+$/.test(op))) {
    const maxLength = Math.max(operator[0].length, operator[1].length);
    operator[0] = operator[0].padStart(maxLength, '0');
    operator[1] = operator[1].padStart(maxLength, '0');

    let result = (parseInt(operator[0], 2) ^ parseInt(operator[1], 2)).toString(2).padStart(maxLength, '0');
    prikazIzpisa.innerHTML = result;
  } else {
    prikazIzpisa.innerHTML = "Napačen vnos";
  }
}

// Ta funkcija izvede logično operacijo NAND.
function bNAND() {
  let operator = vnos.split(' NAND ');
  if (operator.length === 2 && operator.every(op => /^[01]+$/.test(op))) {
    const maxLength = Math.max(operator[0].length, operator[1].length);
    operator[0] = operator[0].padStart(maxLength, '0');
    operator[1] = operator[1].padStart(maxLength, '0');

    let result = '';
    for (let i = 0; i < maxLength; i++) {
      result += (operator[0][i] === '1' && operator[1][i] === '1') ? '0' : '1';
    }
    prikazIzpisa.innerHTML = result;
  } else {
    prikazIzpisa.innerHTML = "Napačen vnos";
  }
}

// Ta funkcija izvede logično operacijo NOR.
function bNOR() {
  let operator = vnos.split(' NOR ');
  if (operator.length === 2 && operator.every(op => /^[01]+$/.test(op))) {
    const maxLength = Math.max(operator[0].length, operator[1].length);
    operator[0] = operator[0].padStart(maxLength, '0');
    operator[1] = operator[1].padStart(maxLength, '0');

    let result = '';
    for (let i = 0; i < maxLength; i++) {
      result += (operator[0][i] === '0' && operator[1][i] === '0') ? '1' : '0';
    }
    prikazIzpisa.innerHTML = result;
  } else {
    prikazIzpisa.innerHTML = "Napačen vnos";
  }
}

// Ta funkcija pregleda vnos in izbere izbranega.
function izpisLogicneVrate() {
  vnos = vnos.trim();

  if (vnos.includes(' AND ')) {
    bAND();
  } else if (vnos.includes(' OR ')) {
    bOR();
  } else if (vnos.includes(' XOR ')) {
    bXOR();
  } else if (vnos.includes(' NAND ')) {
    bNAND();
  } else if (vnos.includes(' NOR ')) {
    bNOR();
  } else {
    prikazIzpisa.innerHTML = "Nisi izbral vrat.";
  }
  vnos = "";
  prikazVnosa.innerHTML = vnos;
}

// Ta funkcija omogoca branje datoeke
document.getElementById('processFile').addEventListener('click', function() {
  const vnosDatoteke = document.getElementById('fileInput');
  if (vnosDatoteke.files.length > 0) {
      const datoteka = vnosDatoteke.files[0];
      const bralec = new FileReader();

      bralec.onload = function(e) {
          const vsebinaDatoteke = e.target.result;
          vnos = vsebinaDatoteke.trim();
          izpisLogicneVrate();
      };

      bralec.readAsText(datoteka);
  } else {
      alert("Izberi datoteko.");
  }
});