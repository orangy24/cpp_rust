#!/usr/bin/env bash
# Copy repo canvases into Cursor's per-workspace canvases folder.
# Cursor only loads *.canvas.tsx from that folder, not from the git tree.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
# /home/david/cpp-rust-kata → home-david-cpp-rust-kata
host="$(echo "$root" | sed 's|^/||; s|/|-|g')"
dest="${CURSOR_CANVASES:-$HOME/.cursor/projects/$host/canvases}"

if [[ ! -d "$dest" ]]; then
  dest="$HOME/.cursor/projects/home-david-cpp-rust-kata/canvases"
fi

if [[ ! -d "$dest" ]]; then
  echo "Cursor canvases dir not found. Open this folder as a Cursor workspace once, then rerun."
  echo "Looked at: $dest"
  exit 1
fi

for f in "$root"/canvases/*.canvas.tsx; do
  [[ -e "$f" ]] || continue
  cp -f "$f" "$dest/$(basename "$f")"
  echo "Linked $(basename "$f") → $dest/"
done
echo "Open the .canvas.tsx from that folder beside chat (Cursor file picker)."
