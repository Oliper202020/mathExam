{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
  ];
  shellHook = ''
    gcc -o myapp \
      main.c \
      percentage/menu.c \
      percentage/percentageCalc.c \
      percentage/vatCalc.c \
      square/menu.c \
      square/rootCalc.c \
      square/squareCalc.c \
      -lm
   '';
}
