# STM32_pojazd
program do sterowania pojazdem zdalnie sterowanym przez sieć Bluetooth. Program w języku C.

program do sterowania pojazdem zdalnie sterowanym przez Bluetooth Program jest napisany na uC STM32F303RE. Program spełnia dwie funkcje:

1. Odbiera dane przesyłane siecią Bluetooth. W rzeczywistości odbiór danych Bluetooth jest dokonany przez układ HC-05 i następnie przez magistralę RS-232 przesyła informacje do uC. W uC następuje analiza odebranych danych i odpowiednie reakcje programu. Program nadający sygnały sterujące był wykonany w C# i nie zawiera się w tym repozytorium.

2. Steruje pracą pojazdu zdalnie sterowanego. Jest to małogabarytowy pojazd który posiada 4 koła typu mecanum. Pojazd posiada 4 silniki które są niezależnie od siebie sterowane, umożliwia to jazdę pojazdu: do przodu, do tyłu, w lewo, w prawo, obrót lewo/prawo, jazdę po skosie. Sterownik został wykonany na płytce drukowanej, posiada 4 mostki H do sterowania silnikami, zasilanie z akumulatorów litowo-jonowych 4x3,6V, przetwornice step-down.
