{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
  ];
  shellHook = ''
      gcc -o main main.c
      gcc -o percentage/menu percentage/menu.c
      gcc -o percentage/momsCalc percentage/momsCalc.c
      gcc -o square/rootCalc percentage/percentageCalc.c
      gcc -o square/rootCalc square/rootCalc.c
      gcc -o square/squareCalc square/squareCalc.c
   '';
}
