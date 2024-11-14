//--

class Item {
    private label: string;
    private volume: number;

    public constructor(label: string, volume: number) {
        this.label = label;
        this.volume = volume;
    }
    public getLabel(): string {
        return this.label;
    }
    public getVolume(): number {
        return this.volume;
    }
    public setVolume(volume: number): void {
        this.volume = volume;
    }
    public setLabel(label: string): void {
        this.label = label;
    }
    public toString(): string {
        return `${this.label}:${this.volume}`;
    }
}

export { Item };