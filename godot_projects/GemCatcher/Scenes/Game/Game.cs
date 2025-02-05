using Godot;
using System;

public partial class Game : Node2D
{
	const double gem_margin = 20.0;
	// [Export] private Gem _gem;
	[Export] private PackedScene _gemScene;
	[Export] private Timer _spawnTimer;
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		// Gem gem = GetNode<Gem>("Gem");
		// _gem.OnScored += OnScored;
		_spawnTimer.Timeout += SpawnGem;
		SpawnGem();
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}

	private void SpawnGem()
	{
		Rect2 vpr = GetViewportRect();
		Gem gem = (Gem)_gemScene.Instantiate();
		AddChild(gem);

		float rX = (float)GD.RandRange(vpr.Position.X + gem_margin, vpr.End.X - gem_margin);
		gem.Position = new Vector2(rX,-100);
		gem.OnScored += OnScored;
		gem.OnGemOffScreen += GameOver;

	}

	private void OnScored()
	{
		GD.Print("OnScored Recieved");
	}

	private void GameOver()
	{
		GD.Print("GameOver");
		foreach (Node node in GetChildren())
		{
			node.SetProcess(false);
		}

		_spawnTimer.Stop();
	}
}
