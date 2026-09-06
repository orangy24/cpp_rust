fn main() {
    cc::Build::new()
        .file("src/pipeline.c")
        .compile("pipeline_c");
    println!("cargo:rerun-if-changed=src/pipeline.c");
}
