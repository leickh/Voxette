// SPDX-License-Identifier: MPL-2.0

const std = @import("std");

pub fn build(build_process: *std.Build) void {
    const target = build_process.standardTargetOptions(.{});
    const optimize = build_process.standardOptimizeOption(.{});

    const library_mod = build_process.addModule("Voxette3D", .{
        .root_source_file = build_process.path("src-zig/root.zig"),
        .target = target,
        .optimize = optimize,
        .link_libc = true,
    });

    const library = build_process.addLibrary(.{
        .linkage = .static,
        .name = "Voxette3D",
        .root_module = library_mod,
    });

    build_process.installArtifact(library);

    const library_unit_tests = build_process.addTest(.{
        .root_module = library_mod,
    });

    const run_library_unit_tests = build_process.addRunArtifact(library_unit_tests);

    const test_step = build_process.step("test", "Run unit tests");
    test_step.dependOn(&run_library_unit_tests.step);
}
