# Study track (Cursor canvas)

Cursor does **not** load `*.canvas.tsx` from the git repo. It only compiles files in:

`$HOME/.cursor/projects/<workspace-id>/canvases/`

This folder is the **source of truth** you commit. After clone (or after editing here):

```bash
chmod +x scripts/link-canvas.sh
./scripts/link-canvas.sh
```

Then open [study-track.canvas.tsx](./study-track.canvas.tsx) from the copied path beside chat. Checkboxes persist in a sidecar next to the Cursor copy (not in git).

Portable tracker (browser, no Cursor): [study/track.html](../study/track.html).

Talk links were checked against YouTube oEmbed (they resolve). If one is blocked in your region, use [youtube.com/@CppCon](https://www.youtube.com/@CppCon) and search the talk title.
