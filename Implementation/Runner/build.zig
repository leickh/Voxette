const std = @import("std");

pub fn build(build_process: *std.Build) void {
    const target = build_process.standardTargetOptions(.{});
    const optimize = build_process.standardOptimizeOption(.{});

    const executable = build_process.addExecutable(.{
        .name = "voxette.elf",
        .root_source_file = build_process.path("src-zig/main.zig"),
        .target = target,
        .optimize = optimize,
    });

    const voxette3d = build_process.dependency("Voxette3D", .{});
    executable.root_module.addImport("Voxette3D", voxette3d.module("Voxette3D"));

    build_process.installArtifact(executable);
    const run_command = build_process.addRunArtifact(executable);
    run_command.step.dependOn(build_process.getInstallStep());

    if (build_process.args) |args| {
        run_command.addArgs(args);
    }

    const run_step = build_process.step("run", "Execute the Voxette game engine");
    run_step.dependOn(&run_command.step);

    const executable_unit_tests = build_process.addTest(.{
        .root_source_file = build_process.path("src-zig/main.zig"),
        .target = target,
        .optimize = optimize,
    });

    const run_executable_unit_tests = build_process.addRunArtifact(executable_unit_tests);

    const test_step = build_process.step("test", "Run all unit tests");
    test_step.dependOn(&run_executable_unit_tests.step);
}
