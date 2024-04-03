class Lead {
    private thickness: number;
    private hardness: string;
    private size: number;
    
    
    public constructor(thickness: number, hardness: string, size: number) {
    }
    public usagePerSheet(): number {
        return 0;
    }
    public toString(): string {
        return `${this.thickness}:${this.hardness}:${this.size}`;
    }
    
    public getThickness(): number {
        return 0;
    }
    public getSize(): number {
        return 0;
    }
    public getHardness(): string {
        return "";
    }
    public setSize(value: number): void {
    }
    public setHardness(value: string): void {
    }
    public setThickness(value: number): void {
    }
}

export { Lead };
