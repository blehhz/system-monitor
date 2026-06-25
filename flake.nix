{
  description = "sysfetch";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-26.05";

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";

    pkgs = import nixpkgs {
      inherit system;
    };

  in {

    devShells.${system}.default =
      pkgs.mkShell {

        packages = with pkgs; [

          clang
          clang-tools

          cmake
          ninja

          gdb
          lldb

          ccache

          pkg-config

          httplib
          nlohmann_json

        ];

        shellHook = ''

          export CC=clang
          export CXX=clang++

          echo "sysfetch dev shell"

        '';

      };

  };

}
